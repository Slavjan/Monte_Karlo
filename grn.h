#pragma once
struct rn
{
	float	*Numbers;
	int		count;
};

class grn
{
private:
	//fields
	//settings
	int		i_number; //setted number or standard radom number 
	int		i_count; // need count for gnerate
	//results
	float	*f_rNumber; // generated namber

	//methods
	//private settings
	void setCount(int);
	void setNumber(int);
	
	int random();

public:	
	grn();
	~grn();
	//settings
	void set(int count, int number);
	// retuning
	int generate();
};

