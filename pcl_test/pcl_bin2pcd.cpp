
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/common/io.h>
#include <pcl/io/pcd_io.h>


using namespace pcl;
using namespace std;

/* ./test input.bin output.pcd */

int main(int argc, char** argv)
{

    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZI>);

    const size_t kMaxNumberOfPoints = 1e6;  
    cloud->clear();
    cloud->reserve(kMaxNumberOfPoints);

    std::string filename = argv[1];

    std::ifstream input(filename, std::ios::in | std::ios::binary);
    if (!input) {
        std::cout << "Could not open pointcloud file.\n";
        return false;
    }

    for (size_t i = 0; input.good() && !input.eof(); i++) {
        pcl::PointXYZI point;
        input.read((char*)&point.x, 3 * sizeof(float));
        input.read((char*)&point.intensity, sizeof(float));
        cloud->push_back(point);
    }
    input.close();

    pcl::io::savePCDFileASCII (argv[2], *cloud);
    std::cerr << "Saved " << cloud->points.size () << " data points to test_pcd.pcd." << std::endl;

    return 0;
}
