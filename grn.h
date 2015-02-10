#pragma once


class grn	//generator of random numbers
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
	//generation
	//std
public:	int random(int n1 = 0, int n2 = 0);
	//algoritmic
	int MMM();//Method of Middle Multiplications
	int MMS();//Method of Middle Squares

	int midExtract(unsigned long int);//extracting a middle of number,
				 					  //for example: ddccccdd, 
									  //the cccc has been extracted and returned
		
public:	
	grn();
	~grn();
	//settings
	void set(int count, int number);
	// retuning
	float generate();
};

