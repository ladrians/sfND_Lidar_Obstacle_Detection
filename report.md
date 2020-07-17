# Sensor Fusion Nanodegree

|Projects|
|---|
|[Lidar Obstacle Detection](https://github.com/ladrians/sfND_Lidar_Obstacle_Detection/blob/master/report.md)|
|[Camera Based 2D Feature Tracking](https://github.com/ladrians/sfND_2D_Feature_Tracking/blob/master/report.md)|
|[3D Object Tracking](https://github.com/ladrians/sfND_3D_Object_Tracking/blob/master/report.md)|
|[Radar Target Generation and Detection](https://github.com/ladrians/sfND_Radar_Target_Generation_and_Detection/blob/master/README.md)|
|[Unscented Kalman Filter Highway](https://github.com/ladrians/sfND_Unscented_Kalman_Filter/blob/master/report.md)|

## Lidar Obstacle Detection Project
Luciano Silveira
June, 2020

### Specification

Followed te steps from the [README](./README.md) file.

### Result

The final result can be checked with this [sample video](./data/sample02.mp4) and compared with the [Course solution sample video](./data/sample01.mp4).

#### Current Implementation

Using Euclidean Custering and RANSAC.

![Sample](./data/sample02.gif)

#### Course Implementation

Using PCL library

![Sample](./data/sample01.png)

## Considerations

The color switching between the detections in consecutive frames details that `Tracking` is needed once an obstacle is detected.

### Links

 * [Original Repository](https://github.com/udacity/SFND_Lidar_Obstacle_Detection)
 * [Project Rubric](https://review.udacity.com/#!/rubrics/2529/view)
