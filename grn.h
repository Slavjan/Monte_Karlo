#pragma once

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
	void setCount(int);
	void setNumber(int);

public:	
	grn();
	~grn();

	


};

