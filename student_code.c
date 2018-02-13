void part_one_classifier(float **data_train,float **data_test)
{
	// PUT YOUR CODE HERE
	// Access the training data using "data_train[i][j]"
	// Training data contains 3 cols per row: X in 
	// index 0, Y in index 1 and Class in index 2
	// Access the test data using "data_test[i][j]"
	// Test data contains 2 cols per row: X in 
	// index 0 and Y in index 1, and a blank space in index 2 
	// to be filled with class
	// The class value could be a 0 or a 1

	float w0=0,wx=0,wy=0,f;
	int i,errors=1000,iterations=0;

	while(errors>0 && iterations<30000)
	{
		errors = 0;
		for(i=0;i<TRAINING_SIZE;i++)
		{
			f = w0 + wx*data_train[i][0] + wy*data_train[i][1];
			if((f>=0 && 2*data_train[i][2]-1<0) || (f<=0 && 2*data_train[i][2]-1>0))
			{
				errors++;
				w0 = w0 + 2*data_train[i][2]-1;
				wx = wx + (2*data_train[i][2]-1)*data_train[i][0];
				wy = wy + (2*data_train[i][2]-1)*data_train[i][1];
			}
		}
		iterations++;
	}

	for(i=0;i<TEST_SIZE;i++)
	{
		f = w0 + wx*data_test[i][0] + wy*data_test[i][1];
		if(f<0)
		{
			data_test[i][2] = 0;
		}
		else
		{
			data_test[i][2] = 1;
		}
	}

}

void part_two_classifier(float **data_train,float **data_test)
{
	// PUT YOUR CODE HERE
	// Access the training data using "data_train[i][j]"
	// Training data contains 3 cols per row: X in 
	// index 0, Y in index 1 and Class in index 2
	// Access the test data using "data_test[i][j]"
	// Test data contains 2 cols per row: X in 
	// index 0 and Y in index 1, and a blank space in index 2 
	// to be filled with class
	// The class value could be a 0 or a 8

	float weights[9][3]={0},f,maxf;
	int i,j,realbutton,maxbutton,errors=1000,iterations=0;

	while(errors>40 && iterations<30000)
	{
		errors = 0;
		for(i=0;i<TRAINING_SIZE;i++)
		{
			maxf = 0;
			maxbutton = 0;
			for(j=0;j<9;j++)
			{
				f = weights[j][0] + weights[j][1]*data_train[i][0] + weights[j][2]*data_train[i][1];
				if(f>maxf)
				{
					maxf = f;
					maxbutton = j;
				}	
			}

			if(maxbutton != data_train[i][2])
			{
				errors++;
				weights[maxbutton][0] -= 1;
				weights[maxbutton][1] -= data_train[i][0];
				weights[maxbutton][2] -= data_train[i][1];
				realbutton = data_train[i][2];
				weights[realbutton][0] += 1;
				weights[realbutton][1] += data_train[i][0];
				weights[realbutton][2] += data_train[i][1];
			}
		}

		iterations++;
	}

	for(i=0;i<TEST_SIZE;i++)
	{
		maxf = 0;
		maxbutton = 0;
		for(j=0;j<9;j++)
		{
			f = weights[j][0] + weights[j][1]*data_test[i][0] + weights[j][2]*data_test[i][1];
			if(f>maxf)
			{
				maxf = f;
				maxbutton = j;
			}	
		}
		data_test[i][2] = maxbutton;

	}

}











