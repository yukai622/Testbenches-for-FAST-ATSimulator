//########################################################################
//##			              EDA Group                               ####
//##                    Politecnico di Torino                         ####
//## Description: Generate the corresponding testbench files for the  ####
//## thermal simulation under steady and transient state.             #### 
//## Input files:  Floorplan fie (.flp)                               ####
//## Output files: Testbench files for steady and transient state     ####
//########################################################################


#include "systemc-ams.h"

#include "temperature.h"
#include "temperature_block.h"
#include "util.h"
#include "flp.h"
#include "string.h"


SCA_TDF_MODULE(rc_network)
{

SCA_CTOR(rc_network){


//using namespace std;


//Read the floorplan file indicates the layout of each component of the system
static char *flp_file = "../example_floorplan_input.flp" ;

// Floorplan
static flp_t *flp;
// Hotspot temperature model
static RC_model_t *model;
// Instantaneous temperature and power values
static double *temp, *power;
// Steady state temperature and power values
static double *overall_power, *steady_temp;


//Initialize floorplan to get adjacency matrix
flp = read_flp(flp_file,FALSE);

//Configure thermal model parameters of the default setting, modily the parameters' values in temperature.cpp file
thermal_config_t config = default_thermal_config();


//Allocate and initialize the RC model
model = alloc_RC_model(&config, flp);

//Generate R and C in the model
populate_R_model(model,flp);
populate_C_model(model,flp);


//Print all values about the MODEL if you want to check them
//debug_print_model(model);


//Get the number of unites of the system 
int num_units = model->block->n_units;

//Print the number of units in your design on the screen
//cout<<"The number of units is \t"<<num_units<<"\n";


//Get the number of total nodes of the system (equal to units' number in block model)
int num_nodes = model->block->n_nodes;

//Print the number of nodes in the generated thermal model
//cout<<"The total number of nodes is \t"<<num_nodes<<"\n";


//Allocate a matrix(num_nodes X num_nodes) to store the resistors between two adjacent nodes
double **r_value = dmatrix(num_nodes,num_nodes);

//Store the values of resistors in the matrix
static int i,j;
for(i=0;i<num_nodes;i++){
	for(j=0;j<num_nodes;j++){
		double tmp1 = model->block->b[i][j];
		double tmp2 = 1/abs(tmp1);
			if(i==j){
				r_value[i][j]=0;	
			}else{
				if(tmp2<999999999){
					r_value[i][j] = tmp2;
				}else{
					r_value[i][j] = 0;
				}
			}
	}
}


fprintf(stdout,"\n");

//Print the values of capacitors in the generated thermal model
//fprintf(stdout,"\n");
//fprintf(stdout, "Printing vector CAPACITANCE:\n");
//dump_dvector(model->block->a, model->block->n_nodes);
//fprintf(stdout,"\n");

//Print the values of resistors convect to environment in the generated themral model
//fprintf(stdout, "Printing resistors between system and environment:\n");
//dump_dvector(model->block->g_amb, model->block->n_units+EXTRA);
//fprintf(stdout,"\n");


// Define all 12 extral nodes in the thermal model
char *extra_nodes[STR_SIZE];

//Four peripheral directional nodes in spreader layer
extra_nodes[0] = "SP_W";
extra_nodes[1] = "SP_E";
extra_nodes[2] = "SP_N";
extra_nodes[3] = "SP_S";
//Four mapped area in heat sink layer from spreader layer
extra_nodes[4] = "SINK_C_W";
extra_nodes[5] = "SINK_C_E";
extra_nodes[6] = "SINK_C_N";
extra_nodes[7] = "SINK_C_S";
//Four peripheral directional nodes in heat sink layer
extra_nodes[8] = "SINK_W";
extra_nodes[9] = "SINK_E";
extra_nodes[10] = "SINK_N";
extra_nodes[11] = "SINK_S";

//Define the character layers array to store the layer name
char *layer_name[10];
//Define the layer name
layer_name[0] = "SILICON";
layer_name[1] = "INTERFACE";
layer_name[2] = "HEATSPREAD";
layer_name[3] = "HEATSINK";



// Define the files to store the scripts for r&c network will be used in simulation
FILE *fp1; // The header file for testbench with temperature trace
FILE *fp2; // The body file for testbench with temperature trace

FILE *fp4; // The header file for testbench with steady temperature
FILE *fp5; // The body file for testbench with steady temperature

//Rename your expected testbench files name for the transient state simulation
fp1 = fopen("../testbench.h","w");
fp2 = fopen("../testbench.cpp","w");

//Rename your expected testbench files name for the steady state simulation
fp4 = fopen("../testbench3_steady.h","w");
fp5 = fopen("../testbench3_steady.cpp","w");



///////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************//
////////////////////////////////For testbench.h file //////////////////////////////////
fprintf(fp1,"/******************************************************/\n");
fprintf(fp1,"/***This file is used to simulated in systemc-ams. ****/\n");
fprintf(fp1,"/***                     EDA                       ****/\n");
fprintf(fp1,"/******************************************************/\n");
fprintf(fp1,"\n\n\n");

//Add the header file
fprintf(fp1,"#include \"systemc-ams.h\"\n");
fprintf(fp1,"\n\n\n");

//Define the number of of your power traces, it shows the number of simulation steps.
fprintf(fp1,"#define NUM \n");


fprintf(fp1,"SCA_TDF_MODULE (testbench)\n"); // The name of the testbench
fprintf(fp1,"{\n"); // { for module

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Start to print inputs and outputs of module in testbench
fprintf(fp1,"\t\t //Interface declaration: output\n");
for(i=0;i<num_units;i++){
	fprintf(fp1,"\t\t sca_tdf::sca_out<double> %s_p; // Power of the %s \n",flp->units[i].name,flp->units[i].name);
}

fprintf(fp1,"\n\n");

fprintf(fp1,"\t\t //Interface declaration: input\n");
for(i=0;i<num_units;i++){
	fprintf(fp1,"\t\t sca_tdf::sca_in<double> %s_t; // Temperature of the %s \n",flp->units[i].name,flp->units[i].name);
}


//Define the array to store the value read from pptrace file.
fprintf(fp1,"\t\t //Vectors to store the value read from .pptrace file\n");
for(i=0;i<num_units;i++){
	fprintf(fp1,"\t\t double %s_val[NUM]; \n",flp->units[i].name);
}

//Print the array to store the tmp value read from thermal modal
fprintf(fp1,"\t\t //Vectors to store the value in .ttrace file read from R&C model\n");
for(i=0;i<num_units;i++){
	fprintf(fp1,"\t\t double %s_tmp[NUM]; \n",flp->units[i].name);
}

//Define the output temperature trace file
fprintf(fp1,"\t\t ofstream mytempfile;\n"); fprintf(fp1,"\n");
fprintf(fp1,"\t\t int counter;\n");

//Declare the CTOR
fprintf(fp1,"\t\t SCA_CTOR(testbench): ");
for(i=0;i<num_units;i++){
	fprintf(fp1," %s_p(\"%s_p\"), ",flp->units[i].name,flp->units[i].name);
}
fprintf(fp1," counter(0) "); fprintf(fp1,"{"); fprintf(fp1,"\n"); fprintf(fp1,"\t\t } \n");

fprintf(fp1,"\n"); 

fprintf(fp1,"\n");

fprintf(fp1,"\t\t void set_attributes(); \n"); 

fprintf(fp1,"\n");

fprintf(fp1,"\t\t void initialize(); \n"); 

fprintf(fp1,"\n");

fprintf(fp1,"\t\t void processing(); \n"); 

fprintf(fp1,"\n\n"); 

fprintf(fp1,"};"); 

fprintf(fp1,"\n\n"); 


////////////////////////////////////////////////////////////////////////////////////////////
//***************************************************************************************//
////////////////////////////////For testbench.cpp file ////////////////////////////////////
fprintf(fp2,"/******************************************************/\n");
fprintf(fp2,"/***This file is used to simulated in systemc-ams. ****/\n");
fprintf(fp2,"/***                     EDA                       ****/\n");
fprintf(fp2,"/******************************************************/\n");
fprintf(fp2,"\n\n\n");
fprintf(fp2,"#include \"testbench.h\"\n");
fprintf(fp2,"\n\n");

//Set attributes for delay 1 ms
fprintf(fp2,"void testbench::set_attributes() \n");
fprintf(fp2,"{\n");
for(i=0;i<num_units;i++){
	fprintf(fp2,"\t %s_p.set_timestep(1,sc_core::SC_MS); \n",flp->units[i].name);
}
fprintf(fp2,"\n\n");
for(i=0;i<num_units;i++){
	fprintf(fp2,"\t %s_p.set_delay(1); \n",flp->units[i].name);
}
fprintf(fp2,"}\n");fprintf(fp2,"\n\n");

//Set the initialization
fprintf(fp2,"void testbench::initialize()\n");
fprintf(fp2,"{\n");
fprintf(fp2,"int j;\n");fprintf(fp2,"\n");

//Rename the power trace file accoding to your file name
fprintf(fp2,"ifstream in(\"../powertrace.txt\");\n");
fprintf(fp2,"if(!in) {\n");
fprintf(fp2,"cout<<\"Cannot open file.\"<<endl;\n");
fprintf(fp2,"exit(-1);\n");
fprintf(fp2,"}\n");
fprintf(fp2,"cout<<\"Power value read...\"<<endl;\n");
fprintf(fp2,"for(j=0;j<NUM;j++) {\n");
fprintf(fp2,"in ");

for(i=0;i<num_units;i++){
	fprintf(fp2," >> %s_val[j]",flp->units[i].name);
}

fprintf(fp2,";\n");
fprintf(fp2,"}\n");
fprintf(fp2,"in.close();\n");fprintf(fp2,"\n\n");
fprintf(fp2,"mytempfile.open(\"../temptrace.txt\");\n");

fprintf(fp2,"\n\n");
fprintf(fp2,"}\n");

fprintf(fp2,"\n");

//Set the processing function
fprintf(fp2,"void testbench::processing()\n");
fprintf(fp2,"{\n");
//Write out the power value according to the values read from the .pptrace
for(i=0;i<num_units;i++){
	fprintf(fp2," \t %s_p.write(%s_val[counter]);\n",flp->units[i].name,flp->units[i].name);
}
fprintf(fp2,"\n");

//Put the headline for the output .ttrace
fprintf(fp2,"if(counter == 0){ \n");
fprintf(fp2,"\t mytempfile ");

for(i=0;i<num_units;i++){
	fprintf(fp2," <<\"%s\"<<\"\\t\"",flp->units[i].name);
}
fprintf(fp2,"<<\"\\n\"; \n");
fprintf(fp2,"}\n");fprintf(fp2,"\n\n");

//Read the temperature from the thermal model 
for(i=0;i<num_units;i++){
	fprintf(fp2," \t %s_tmp[counter] = %s_t.read() + 313.15-273.15;\n",flp->units[i].name,flp->units[i].name);
}
//Store the temperature file into the .ttrace file
for(i=0;i<num_units;i++){
	fprintf(fp2," \t mytempfile <<std::setprecision(10)<< %s_tmp[counter] <<\"\\t\";\n",flp->units[i].name);
}

fprintf(fp2,"\n");
fprintf(fp2,"\t counter++; \n\n");

fprintf(fp2,"\t if(counter == NUM){\n");
fprintf(fp2,"\t\t sc_stop();\n");
fprintf(fp2,"\t}\n");
fprintf(fp2,"}\n\n\n");

/////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************************************************************///
////////////////////////////////For testbench_steady.h file /////////////////////////////////////////
fprintf(fp4,"/******************************************************/\n");
fprintf(fp4,"/***This file is used to simulated in systemc-ams. ****/\n");
fprintf(fp4,"/***                     EDA                       ****/\n");
fprintf(fp4,"/******************************************************/\n");
fprintf(fp4,"\n\n\n");

fprintf(fp4,"#include \"systemc-ams.h\"\n");
fprintf(fp4,"\n\n");


fprintf(fp4,"#define NUM \n");
fprintf(fp4,"SCA_TDF_MODULE (testbench)\n"); // The name of the thermal model 
fprintf(fp4,"{\n"); // { for module

//Define the inputs and outputs of the testbench
fprintf(fp4,"\t\t //Interface declaration: output\n");
for(i=0;i<num_units;i++){
	fprintf(fp4,"\t\t sca_tdf::sca_out<double> %s_p; // Power of the %s \n",flp->units[i].name,flp->units[i].name);
}

fprintf(fp4,"\n\n");

fprintf(fp4,"\t\t //Interface declaration: input\n");
for(i=0;i<num_units;i++){
	fprintf(fp4,"\t\t sca_tdf::sca_in<double> %s_t; // Power of the %s \n",flp->units[i].name,flp->units[i].name);
}
fprintf(fp4,"\n\n");


//Define the vectors to store the power values from the power trace file
fprintf(fp4,"\t\t //Vectors to store the value read from .pptrace file\n");
for(i=0;i<num_units;i++){
	fprintf(fp4,"\t\t double %s_val[NUM]; \n",flp->units[i].name);
}


fprintf(fp4,"\n\n");

//Define the sum of all power values for compute the average power consumption values of each component
fprintf(fp4,"\t\t //Store sum \n");
for(i=0;i<num_units;i++){
	fprintf(fp4,"\t\t double sum_%s; \n",flp->units[i].name);
}

//Define the average power consumption of each component
fprintf(fp4,"\n\n");
fprintf(fp4,"\t\t //Store avg \n");
for(i=0;i<num_units;i++){
	fprintf(fp4,"\t\t double avg_%s; \n",flp->units[i].name);
}

//Define the variable to store the steady state temperature of each component
fprintf(fp4,"\n");fprintf(fp4,"\n");
fprintf(fp4,"\t\t //Store value from thermal model \n");
for(i=0;i<num_units;i++){
	fprintf(fp4,"\t\t double temp_%s; \n",flp->units[i].name);
}

fprintf(fp4,"\t\t ofstream mytempfile;\n");
fprintf(fp4,"\n");
fprintf(fp4,"\t\t int counter;\n\n");

fprintf(fp4,"\t\t SCA_CTOR(testbench): ");

for(i=0;i<num_units;i++){
	fprintf(fp4," %s_p(\"%s_p\"), ",flp->units[i].name,flp->units[i].name);
}

fprintf(fp4," counter(0) ");

fprintf(fp4,"{");

fprintf(fp4,"\n");

fprintf(fp4,"\t } \n");

fprintf(fp4,"\n\n");

fprintf(fp4,"\t\t void set_attributes(); \n");fprintf(fp4,"\n");

fprintf(fp4,"\t\t void initialize(); \n");fprintf(fp4,"\n

fprintf(fp4,"\t\t void processing(); \n");fprintf(fp4,"\n\n");
fprintf(fp4,"};");

fprintf(fp4,"\n\n");


/////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************************************************************///
////////////////////////////////For testbench_steady.cpp file ///////////////////////////////////////
fprintf(fp5,"/******************************************************/\n");
fprintf(fp5,"/***This file is used to simulated in systemc-ams. ****/\n");
fprintf(fp5,"/***                     EDA                       ****/\n");
fprintf(fp5,"/******************************************************/\n");
fprintf(fp5,"\n\n\n");

fprintf(fp5,"#include \"testbench.h\"\n");

fprintf(fp5,"\n\n\n");

//Set one delay for the first simluation step
fprintf(fp5,"void testbench::set_attributes() \n");
fprintf(fp5,"{\n");

for(i=0;i<num_units;i++){
	fprintf(fp5,"\t %s_p.set_timestep(1,sc_core::SC_MS); \n",flp->units[i].name);
}

fprintf(fp5,"\n\n");
for(i=0;i<num_units;i++){
	fprintf(fp5,"\t %s_p.set_delay(1); \n",flp->units[i].name);
}

fprintf(fp5,"}\n");

fprintf(fp5,"\n\n");

//Populate the initialize function
fprintf(fp5,"void testbench::initialize()\n");
fprintf(fp5,"{\n");

fprintf(fp5,"\t int j;\n");
fprintf(fp5,"\n");

fprintf(fp5,"\t ifstream in(\"../powertrace.txt\");\n");

fprintf(fp5,"\t if(!in) {\n");
fprintf(fp5,"\t\t cout<<\"Cannot open file.\"<<endl;\n");
fprintf(fp5,"\t exit(-1);\n");
fprintf(fp5,"\t }\n");

fprintf(fp5,"\t cout<<\"Power value read...\"<<endl;\n");

fprintf(fp5,"\t for(j=0;j<NUM;j++) {\n");
fprintf(fp5,"\t in ");
for(i=0;i<num_units;i++){
	fprintf(fp5," >> %s_val[j]",flp->units[i].name);
}
fprintf(fp5,";\n");
fprintf(fp5,"\t}\n");

fprintf(fp5,"\t in.close();\n");
fprintf(fp5,"\n\n");

//Open the output temperature trace file 
fprintf(fp5,"\t mytempfile.open(\"../temptrace.txt\");\n");
fprintf(fp5,"\n\n");

fprintf(fp5,"}\n");
fprintf(fp5,"\n");

//Populate the processing function
fprintf(fp5,"void testbench::processing()\n");
fprintf(fp5,"{\n");

fprintf(fp5,"\t int i;\n");

//Initialize all the variables of sum of power consumption of each component
for(i=0;i<num_units;i++){
	fprintf(fp5," \t sum_%s =0;\n",flp->units[i].name);
}


fprintf(fp5,"\n\n");

fprintf(fp5,"\t for(i=0;i<NUM;i++){\n");

for(i=0;i<num_units;i++){
	fprintf(fp5," \t\t sum_%s +=%s_val[i];\n",flp->units[i].name,flp->units[i].name);
}

fprintf(fp5,"\t }\n");
fprintf(fp5,"\n\n");

//Compute the average power consumption of each component
for(i=0;i<num_units;i++){
fprintf(fp5," \t avg_%s = sum_%s/NUM;\n",flp->units[i].name,flp->units[i].name);
}

fprintf(fp5,"\n\n");

//Send the power values to thermal model
for(i=0;i<num_units;i++){
fprintf(fp5," \t %s_p.write(avg_%s);\n",flp->units[i].name,flp->units[i].name);
}

//Read the temperature values from thermal model
fprintf(fp5,"\n");fprintf(fp5,"\n");
for(i=0;i<num_units;i++){
fprintf(fp5," \t temp_%s = %s_t.read()+313.15;\n",flp->units[i].name,flp->units[i].name);
}

fprintf(fp5,"\n\n");

for(i=0;i<num_units;i++){
fprintf(fp5," \t mytempfile <<std::setprecision(10)<< temp_%s <<\"\\t\";\n",flp->units[i].name);
}

fprintf(fp5,"}\n\n"); 


}//CTOR	

};//MODULE
