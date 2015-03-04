#include "point.h"

class Edge
{
private:
	//private fields
	Point*	P_dot;
	int		i_k;
	int		i_b;
	bool	b_horizontal;
	bool	b_vertical;

public:
	// public methods
	Edge();
	~Edge();

	// initing
	void	setPoints(Point, Point);
	void	setPoints(Point*, Point*);
	void	setPoints(int x1, int x2, int y1, int y2);

	//calculatins
	void	calculateAngle();
	bool	collision(Point  p);
	bool	collision(Point* p);
	// getting fields
	Point	getDot(int);
	int		getDotX(int);   
	int		getDotY(int);
	int		getK();
	int		getB();
	bool	getHorizont();
	bool	getVertical();
};
