# Testbenches-for-FAST-ATSimulator

After you derive the thermal model, you need stimuli generation through the construction of a dedicated testbench, implemented either as (a) a trace of power consumption values, or (b) by simulating the thermal model concurrently with functional and power execution.

As shown in the belwo flow chart, the two kinds of stimuli list in the bottom box. This repository help you build the testbenches automatically for (a). These testbenches are different for steady state simulation or transient state simulation. 

![1.png](https://steemitimages.com/DQmRSHNr3yikNfUUNo5LKptdMTYdYXP49w5Cit5arseT7gh/1.png)

(* Concerning the concurrent simluation with other different extra-functional properties, please refer to : *Vinco, S., Chen, Y., Fummi, F., Macii, E. and Poncino, M., 2017. A Layered Methodology for the Simulation of Extra-Functional Properties in Smart Systems. IEEE Transactions on Computer-Aided Design of Integrated Circuits and Systems.* )
