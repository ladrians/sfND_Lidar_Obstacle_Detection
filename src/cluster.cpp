/* \author Aaron Brown */
/* Tweaked implementation to fix Project Rubric
*/

#include <chrono>
#include <string>
#include "kdtree.h"
//#include "quiz/cluster/kdtree.h"
#include <iostream>
#include <pcl/common/common.h>


void clusterHelper(const std::vector<std::vector<float>>& points, KdTree* tree, float distanceTol, int i, std::vector<int> &cluster, std::vector<bool> &processed){
	if(processed[i]) return;
	cluster.push_back(i);
	processed[i] = true;

	std::vector<int> nearby = tree->search(points[i], distanceTol);
	for(auto &j: nearby){
		clusterHelper(points, tree, distanceTol, j, cluster, processed);
	}
}


void euclideanCluster(const std::vector<std::vector<float>>& points,  float clusterTolerance, int minSize,
		int maxSize, std::vector<pcl::PointIndices> &cluster_indices)
{
	if(points.size() < minSize){
		return;
	}
	KdTree tree;

	for (int i=0; i<points.size(); i++)
		tree.insert(points[i],i);

	std::vector<bool> processed(points.size(), false);
	for(int i=0; i< points.size(); i++){
		if(processed[i]) continue;
		std::vector<int> cluster;
		clusterHelper(points, &tree, clusterTolerance, i, cluster, processed);
		uint cluster_size = cluster.size();
		if(cluster_size < minSize || cluster_size > maxSize){
			continue;
		}
		pcl::PointIndices indices;
		indices.indices = std::move(cluster);
		cluster_indices.push_back(indices);
	}
	return;
}