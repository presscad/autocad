#include "elements2d.h"
#include "elements3d.h"
#include "eigen3/Eigen/Dense"
#include <math.h>
using namespace std;

class projection
{
	public:
	object3d Solid;
	object2d proj;
	object2d project(object3d obj, vector<double> direction)
	{
		
	}
	Vertex2d project_v(Vertex3d v, vector<double> direction)
	{
		///
		/// Finds out the projection of a 3D vertex given a plane of projection
		///	
		double angle = rotation_angle(direction);
		vector<double> rot_axis;
		rot_axis.push_back(direction[1]);
		rot_axis.push_back(-1 * direction[0]);
		rot_axis.push_back(0);
		v.rotate(rot_axis, angle);
		v.z = 0;
	}

	Edge2d project_e(Edge3d e, vector<double> direction)
	{
		Edge2d e1;
		e1.v1 = project_v(e.v1, direction);
		e1.v2 = project_v(e.v2, direction);
		e1.hidden = false;
	}
	theta rotation_angle(vector<double> direction)
	{
		double a = direction[0];
		double b = direction[1];
		double c = direction[2];
		double s2 = (a*a) + (b*b) + (c*c);
		double s = sqrt(s2);
		double costheta = c / s;
		double theta = arccosine(costheta);
		return theta;
	}
};