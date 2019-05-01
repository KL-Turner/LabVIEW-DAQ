# LabVIEW-DAQ VIs and Hardware
LabVIEW VIs for whisker tracking and force sensor analysis to supplement animal behavioral characterization during two photon microscopy.

https://kl-turner.github.io/LabVIEW-DAQ/

LabVIEW VIs for behavioral characterization for both Two Photon and Intrinsic Optical Signal imaging set-ups. This README will break down the different components and give a brief run-down of the respective parameters.
The documentation, user manuals, diagrams, and spec sheets linked in this repository are freely available online or upon request. **The company names and product names outlined in this README are trademarks, registered trademarks, or copyrights of the respective companies.**

This repository has two main folders that hold the project files and associated subVIs for the Two Photon and IOS components. To open the Front panel, naviate to either fold and either open the labview project file(.lvproj) or the *MasterAcquisionFile_[2P/IOS]* file. I recommend opening the MasterAcquitionFile directly. Do not be overwhelmed by the block diagrams - Ideally, much of the Master VI's content would be subdivided into smaller more dedicated VIs, however, due to the re-iterative nature of these projects and how the legacy versions of these codes were originally written, the majority of the project's contents lies within the Master VI even though this is against good (graphical) coding practices.

## Two-Photon Excitation Microscopy

| ![](https://user-images.githubusercontent.com/30758521/56225071-b1e00c00-603e-11e9-8020-caa8a4924ce7.PNG) |
|:----:|
| *Figure 1: MasterAcquisionFile_IOS Front Panel* |

This VI runs in synchony with MScan, starting from a TTL trigger sent by MScan's scanning initiation. When run, the VI will initiate all of the hardware paths to reduce the lag time between MScan and the VI starting. It will then stand in a while loop until the designated pin receives the trigger, ending the loop and entering the DAQ loops. A Notes section for experimental parameters and any analog signals will be saved to a .tdms file with a .tdms_index file giving the parameter indeces. Any camera files are saved independently with their own respective (typically .bin) extensions. The force sensor signal is duplicated to both MScan and LabVIEW so that any remaining delay between the two can be corrected in-post. 

Numerous indicator lights signal the current status of the program. Once DAQ starts, the webcam (large rectangle) and whisker camera (narrow rectange) will give real-time monitoring of the camera feeds. Numerous monitors of the analog samples, whisker camera sampling rate, and web cam sampling rate allow the user to troubleshoot any issues. A dropped-frames meter will monitor the dropped whisker camera frames. Note that the webcam is just for general purposes, and is actually not being triggered. The webcam's settings, depending on the model, can be modulated in NI MAX. While many webcams are IR sensitive, nearly all have a filter that can be removed. This is important because any significant amounts of light will pop the PMTs/ruin your image. We use a webcam as opposed to a more expensive camera because the movies are smaller in size and are only used for strange events and real-time monitoring, not in any significant data analysis. There are numerous controls for folder paths and hardware/camera IDs. For any questions regarding these, consult your respective National Instruments Device documentation and NI MAX settings. 

### Equipment

| Hardware, Manufacture                         | Documentation                                                                                                | Purpose                                             |
| :---                                          | :---                                                                                                         | :---                                                |
| Spectra-Physics Mai Tai Ti:Sapphire laser     | https://www.spectra-physics.com/products/ultrafast-lasers/mai-tai                                            | Two-photon laser                                    |
| National Instruments PCIe-6353                | http://www.ni.com/en-us/support/model.pcie-6353.html                                                         | Integrates various components with MScan            |
| National Instruments PCIe-6321                | http://www.ni.com/en-us/support/model.pcie-6321.html                                                         | Integrates various components with MScan            |
| National Instruments BNC-2110 (x4)            | http://sine.ni.com/nips/cds/view/p/lang/en/nid/1865                                                          | Integrates various components with MScan            |
| National Instruments USB-6211                 | http://www.ni.com/en-us/support/model.usb-6211.html                                                          | DAQ for webcam, force sensor, whisker cam           |
| Sutter Instruments PS-2LV                     | https://www.sutter.com/MICROSCOPES/pmt_frame.html                                                            | PMT power supply                                    | 
| Sutter Instruments MDR-6                      | See new Resonant version MDR-R https://www.sutter.com/MICROSCOPES/resscan.html                               | Scan drive controller                               |
| Sutter Intruments MPC-200                     | https://www.sutter.com/MICROMANIPULATION/mpc200.html                                                         | Objective micromanipulator                          |
| Conoptics Model 350-80LA                      | https://www.conoptics.com/modulation-systems-mpm/                                                            | Electro-Optic modulator, control laser intensity    |
| Conoptics Model 320RM                         | https://www.conoptics.com/modulation-systems-mpm/                                                            | Pockel cell controller                              |
| Uniblitz VCM-D1                               | https://www.uniblitz.com/products/vcm-d1-shutter-driver/                                                     | Shutter driver and controller                       |
| Femto DHPCA-100 (x2)                          | https://www.femto.de/en/products/current-amplifiers/variable-gain-up-to-200-mhz-dhpca.html                   | Variable gain high-speed current amplifier for PMTs |
| Nikon CFI75 LWD 16X W Objective               | https://www.nikon.com/products/microscope-solutions/lineup/objectives/cfi75_water_dipping_series/index.htm   | Water immersion objective                           |
| Thorlabs LEDs M780L3 (x2)                     | https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=2692&pn=M780L3#4426                                | 2 Infrared for whisker/webcam                       |
| Thorlabs LEDD1B T-Cube LED Driver (x5)        | https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=2616                                               | Power and illumination control for Thorlabs LEDs    |
| Newport KPX124 Plano-Convex Lens (x1)         | https://www.newport.com/p/KPX124                                                                             | General lens for Thorlabs LEDs                      |
| Basler ace acA640-120gm (camera)              | https://www.baslerweb.com/en/products/cameras/area-scan-cameras/ace/aca640-120gm/                            | Whisker tracking camera                             |
| Edmund Optics 35mm C Series VIS-NIR FFL Lens  | https://www.edmundoptics.com/p/35mm-c-series-vis-nir-fixed-focal-length-lens/22384/                          | Lens for whisker camera                             |
| Tekscan FlexiForce quickstart board           | https://www.tekscan.com/products-solutions/electronics/flexiforce-quickstart-board                           | Force sensor for movement detection                 |
| ELP 2.8mm wide angle IR LED Infrared USB camera                   | https://www.amazon.com/gp/product/B01E8OX14K/ref=ppx_yo_dt_b_asin_title_o01_s01?ie=UTF8&psc=1                                  | General purpose webcam                              |
| RW Automation Solenoid Control Board SC5      | http://www.rwautomation.com/                                                                                 | Control board for whisker, auditory stimulation     |
| STC Solenoid Valve 2V035-1/4 (x3)             | https://www.stcvalve.com/Solenoid-Valve/2V025-035.htm                                                        | Solenoid valve that directs 10 psi of air           |
| World Precision Instruments DAM80 (X2)        | https://www.wpiinc.com/sys-dam80-extracellular-amplifier-with-active-probe                                   | Diff Amp for 1 neural electrode, 1 EMG              |
| Stanford Research Systems Model SR560         | https://www.thinksrs.com/products/sr560.html                                                                 | Preamplifier for force sensor                       |
| TENMA Dual Power supply 72-8690A (x2)         | https://www.newark.com/tenma/72-8690a/power-supply-2ch-32v-3a-adj-fixed/dp/47X1649                           | Power for Basler camera, solenoids, force sensor    |

See https://www.edmundoptics.com/search/?criteria=mirror%20coating for mirror options to direct laser path. 

### Block Diagram

| ![](https://user-images.githubusercontent.com/30758521/56225266-01bed300-603f-11e9-8e37-1f9290c72129.png) |
|:----:|
| *Figure 2: MasterAcquisionFile_2P Block Diagram* |

## Intrinsic Optical Signal (IOS) Reflectance Imaging

| ![](https://user-images.githubusercontent.com/30758521/56225298-13a07600-603f-11e9-8836-ba6a879f88ea.PNG) |
|:----:|
| *Figure 3: MasterAcquisionFile_IOS Front Panel* |

This VI runs independently and acquires all data itself. It shares all the same monitoring and control attributes as the Two Photon VI described above, as well as several more. In addition to the webcam and whisker camera feeds, this VI also shows the pupil diameter and IOS window in real-time.

### Equipment

| Hardware, Manufacture                         | Documentation                                                                              | Purpose                                             |
| :---                                          | :---                                                                                       | :---                                                |
| National Instruments PCI-6259                 | http://sine.ni.com/nips/cds/view/p/lang/en/nid/14128                                       | Device interface for DAQ and counter outputs        |
| National Instruments BNC-2090A                | http://sine.ni.com/nips/cds/view/p/lang/en/nid/203462                                      | BNC interface for PCI-6259                          |
| National Instruments USB-6343                 | http://www.ni.com/en-us/support/model.usb-6343.html                                        | Additional counter output                           |
| National Instruments PCI-1428                 | http://www.ni.com/en-us/support/model.pci-1428.html                                        | Framegrabber for DALSA 1M60 camera                  |
| Teledyne DALSA 1M60 (camera)                  | https://www.teledynedalsa.com/en/products/imaging/cameras/                                 | IOS reflectance camera                              |
| Edmund Optics VZM 300i Zoom Imaging Lens      | https://www.edmundoptics.com/p/vzmtrade-300i-zoom-imaging-lens/10634/                      | Lens for IOS camera                                 |
| Edmund Optics M22.5x0.5 Green Filter          | https://www.edmundoptics.com/p/mounted-m225-x-05-threaded-green-filter/6901/               | Bandpass filter for IOS camera                      |
| Thorlabs LEDs M530L3 (x4), M780L3 (x1)        | https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=2692&pn=M780L3#4426              | 4 green IOS LEDs, 1 Infrared for pupil tracking     |
| Thorlabs FB530-10 Bandpass filter (x4)        | https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=2616                             | Bandpass Filter for IOS Thorlabs LEDs               |
| Thorlabs LEDD1B T-Cube LED Driver (x5)        | https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=2616                             | Power and illumination control for Thorlabs LEDs    | 
| Newport KPX076 Plano-Convex Lens (x5)         | https://www.newport.com/p/KPX076                                                           | Columnating lens for Thorlabs LEDs                  |
| Basler ace acA640-120gm (camera)              | https://www.baslerweb.com/en/products/cameras/area-scan-cameras/ace/aca640-120gm/          | Whisker tracking camera                             |
| Edmund Optics 18mm DG Series FFL Lens         | https://www.edmundoptics.com/p/18mm-dg-series-fixed-focal-length-lens/11591/               | Lens for whisker camera                             |
| Edmund Optics 50x50mm 660nm LED backlight     | https://www.edmundoptics.com/p/50-x-50mm-660nm-led-backlight/21332/                        | Illuminates whiskers for whisker camera             |
| Edmund Optics 75 mm DG Series FFL Lens  | https://www.edmundoptics.com/p/75mm-dg-series-fixed-focal-length-lens/11371/        | Lens for pupil camera                               |
| Tekscan FlexiForce quickstart board           | https://www.tekscan.com/products-solutions/electronics/flexiforce-quickstart-board         | Force sensor for movement detection                 |
| Microsoft Lifecam Cinema                      | https://www.microsoft.com/accessories/en-us/products/webcams/lifecam-cinema/h5d-00013      | General purpose webcam                              |
| RW Automation Solenoid Control Board SC5      | http://www.rwautomation.com/                                                               | Control board for whisker, auditory stimulation     |
| STC Solenoid Valve 2V035-1/4 (x3)             | https://www.stcvalve.com/Solenoid-Valve/2V025-035.htm                                      | Solenoid valve that directs 10 psi of air           |
| World Precision Instruments DAM80 (x3)        | https://www.wpiinc.com/sys-dam80-extracellular-amplifier-with-active-probe                 | Diff Amp for 2 neural electrodes, 1 EMG             |
| Brownlee Precision Model 440 Amplifier        | http://www.brownleeprecision.com/products/amplifier-model-440/                             | Amplification of force sensor, filter MUA for audio |
| Tektronix TDS 2014C Oscilloscope (x2)         | https://www.tek.com/oscilloscope/tds2000-digital-storage-oscilloscope                      | Monitor signals in real time                        |
| TENMA Dual Power supply, 280W (x2)            | http://www.tenma.com/                                                                      | Power for Basler cameras, solenoids, force sensor   |

Both imaging systems are built with numerous Thorlabs components, in particular https://www.thorlabs.com/navigation.cfm?guide_id=50 on vibration-isolation optical tables.

### Block Diagram
| ![](https://user-images.githubusercontent.com/30758521/56225312-1d29de00-603f-11e9-96fe-c1e7ee181918.png) |
|:----:|
*Figure 4: MasterAcquisionFile_IOS Block Diagram*

### Block Diagram
| ![](https://user-images.githubusercontent.com/30758521/56225312-1d29de00-603f-11e9-96fe-c1e7ee181918.png) |
|:----:|
| *Figure 4: MasterAcquisionFile_IOS Block Diagram* |

# Acknowledgements
* A significant amount of the IOS LabVIEW code was initially written by Dr. Patrick J. Drew.
* Dr. Aaron T. Winder re-designed/improved the IOS code and built the original IOS DAQ setup. 
* Kevin L. Turner redesigned/organized the IOS Front Panel and Block Diagram, adding the pupil tracking. He (I) used a significant portion of the IOS code to then design and create the Two Photon code and DAQ hardware setup.

#### Feel free to contact Kevin Turner (klt8@psu.edu) with any questions regarding the hardware or VIs. 
