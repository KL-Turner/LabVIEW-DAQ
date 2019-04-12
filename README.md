# LabVIEW-DAQ
LabVIEW VIs for behavioral characterization for both Intrinsic Optical Signal and Two-Photon imaging set-ups. This README will break down the different components and give a brief run-down of the respective parameters.
The documentation, user manuals, diagrams, and spec sheets linked in this repository are freely available online or upon request, and are compiled in this repository for educational/research purposes only. **The company names, product names, and documentation outlined in this README are trademarks, registered trademarks, or copyrights of the respective companies.**

## Two-Photon Excitation Microscopy
### Equipment

| Hardware, Manufacture              | Documentation                                                                                             | Purpose                  |
| :---                               | :---     
| Spectra :)                         | https://www.spectra-physics.com/products/ultrafast-lasers/mai-tai


                                                                                                 | :---                     |
| Teledyne Dalsa 1M60 (camera)       | https://www.teledynedalsa.com/en/products/imaging/cameras/             | IOS reflectance camera   |
| Basler ace acA640-120gm (camera)    | https://www.baslerweb.com/en/products/cameras/area-scan-cameras/ace/aca640-120gm/          | Whisker tracking         |
| Basler ace acA640-120gm (camera)    | "                                                                                                         | Pupil tracking
| Microsoft Lifecam Cinema           | https://www.microsoft.com/accessories/en-us/products/webcams/lifecam-cinema/h5d-00013                     | General purpose webcam



Microsoft LifeCam Studio Webcam
https://www.microsoft.com/accessories/en-us/products/webcams/lifecam-studio/q2f-00013





| Analysis Toggle Option (on/off)    | Default Value   | Description                                                                                                          |
| :---                               | :---            | :---                                                                                                                 |
| Hippocampal LFP                    | on              | Use the Hippocampal LFP (Delta/Theta Rhythms) in scoring analysis (recommended).                                     |
| Ball Velocity                      | on              | Use the ball velocity in scoring analysis (recommended).                                                             |
| Heart Rate                         | on              | Use the heart rate in scoring analysis (optional).                                                                   |
| Save SleepData.mat Structure       | on              | Save structure containing results under the Analysis indentifier label.                                              |
| Save Single Trial Summary Figures  | off             | If sleep events are found, create a summary figure and save it in a folder under the Analysis indentifier label.     |
| Anaylze Processed Data**           | off             | Re-run the block that calculates individual neural bands and binarizes the ball velocity threshold.                  |
| Anaylze Data Categorization**      | off             | Re-run the block that categorizes the behavior using ball velocity and whisker puff times.                           |
| Anaylze Spectrograms**             | off             | Re-run the block that analyzes the spectrogram of the neural data.                                                   |
| Anaylze Resting Baselines**        | off             | Re-run the block that calculates the resting baselines during resting periods (default periods >= 10 seconds)        |

Hit the green 'GO.' button to begin the analysis. A set loading bars will be displayed that keeps track the analysis' progression. The only prompts occur in block one, where the user is requested an input to define the ball velocity's acceleration threshold. Follow the prompts to set and then confirm the threshold value. This will occur for each unique day of imaging.