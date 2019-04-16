# LabVIEW-DAQ
LabVIEW VIs for behavioral characterization for both Intrinsic Optical Signal and Two-Photon imaging set-ups. This README will break down the different components and give a brief run-down of the respective parameters.
The documentation, user manuals, diagrams, and spec sheets linked in this repository are freely available online or upon request, and are compiled in this repository for educational/research purposes only. **The company names, product names, and documentation outlined in this README are trademarks, registered trademarks, or copyrights of the respective companies.**

## Two-Photon Excitation Microscopy
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
| Newport KPX076 Plano-Convex Lens (x1)         | https://www.newport.com/p/KPX076                                                                             | Columnating lens for Thorlabs LEDs                  |
| Basler ace acA640-120gm (camera)              | https://www.baslerweb.com/en/products/cameras/area-scan-cameras/ace/aca640-120gm/                            | Whisker tracking camera                             |
| Edmund Optics 35mm C Series VIS-NIR FFL Lens  | https://www.edmundoptics.com/p/35mm-c-series-vis-nir-fixed-focal-length-lens/22384/                          | Lens for whisker camera                             |
| Tekscan FlexiForce quickstart board           | https://www.tekscan.com/products-solutions/electronics/flexiforce-quickstart-board                           | Force sensor for movement detection                 |
| Generic Infrard USB Webcam                    | https://www.amazon.com/s?k=infrared+usb+webcam&i=electronics&ref=nb_sb_noss                                  | General purpose webcam                              |
| RW Automation Solenoid Control Board SC5      | http://www.rwautomation.com/                                                                                 | Control board for whisker, auditory stimulation     |
| STC Solenoid Valve 2V035-1/4 (x3)             | https://www.stcvalve.com/Solenoid-Valve/2V025-035.htm                                                        | Solenoid valve that directs 10 psi of air           |
| World Precision Instruments DAM80 (X2)        | https://www.wpiinc.com/sys-dam80-extracellular-amplifier-with-active-probe                                   | Diff Amp for 1 neural electrode, 1 EMG              |
| Stanford Research Systems Model SR560         | https://www.thinksrs.com/products/sr560.html                                                                 | Preamplifier for force sensor                       |
| TENMA Dual Power supply 72-8690A (x2)         | https://www.newark.com/tenma/72-8690a/power-supply-2ch-32v-3a-adj-fixed/dp/47X1649                           | Power for Basler camera, solenoids, force sensor    |

See https://www.edmundoptics.com/search/?criteria=mirror%20coating for mirror options to direct laser path. 

## Intrinsic Optical Signal (IOS) Reflectance Imaging
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
| Edmund Optics 16mm C Series VIS-NIR FFL Lens  | https://www.edmundoptics.com/p/16mm-c-series-vis-nir-fixed-focal-length-lens/22382/        | Lens for pupil camera                               |
| Tekscan FlexiForce quickstart board           | https://www.tekscan.com/products-solutions/electronics/flexiforce-quickstart-board         | Force sensor for movement detection                 |
| Microsoft Lifecam Cinema                      | https://www.microsoft.com/accessories/en-us/products/webcams/lifecam-cinema/h5d-00013      | General purpose webcam                              |
| RW Automation Solenoid Control Board SC5      | http://www.rwautomation.com/                                                               | Control board for whisker, auditory stimulation     |
| STC Solenoid Valve 2V035-1/4 (x3)             | https://www.stcvalve.com/Solenoid-Valve/2V025-035.htm                                      | Solenoid valve that directs 10 psi of air           |
| World Precision Instruments DAM80 (x3)        | https://www.wpiinc.com/sys-dam80-extracellular-amplifier-with-active-probe                 | Diff Amp for 2 neural electrodes, 1 EMG             |
| Brownlee Precision Model 440 Amplifier        | http://www.brownleeprecision.com/products/amplifier-model-440/                             | Amplification of force sensor, filter MUA for audio |
| Tektronix TDS 2014C Oscilloscope (x2)         | https://www.tek.com/oscilloscope/tds2000-digital-storage-oscilloscope                      | Monitor signals in real time                        |
| TENMA Dual Power supply, 280W (x2)            | http://www.tenma.com/                                                                      | Power for Basler cameras, solenoids, force sensor   |

Both imaging systems are built with numerous Thorlabs components, in particular https://www.thorlabs.com/navigation.cfm?guide_id=50 on vibrasion isolation optical tables.