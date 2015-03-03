#pragma once


class grn	//generator of random numbers
{
private:

	//methods
	//private settings
	int setNumber();

	int midExtract(unsigned long int);//extracting a middle of number,
				 					  //for example: ddccccdd, 
									  //the cccc has been extracted and returned

public:
    grn();
	~grn();

	//generation
	//std
	int random(int n1 = 0, int n2 = 0);
	//algoritmic
	int MMM(int firstNumber = 0);//Method of Middle Multiplications
	int MMS(int n = 0);//Method of Middle Squares

			
	

	// retuning
	float generate();
};

