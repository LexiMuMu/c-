	if(degree > 2)
	{
		if(coefficient[1] == 1)
			cout << "x^" << degree - 1;
		else if(coefficient[degree - 1] > 1)
			cout << coefficient[degree - 1] << "x^" << degree - 1;
		if(coefficient[degree - 1] < 0)
			cout << coefficient[degree - 1] << "x^" << degree - 1;
	}
	else if(coefficient[1] != 0 && degree == 1)
	{
		if(coefficient[1] == 1)
			cout << "x";
		else if(coefficient[1] > 1)
			cout << "+" << coefficient[1] << "x";
		else if(coefficient[1] < 0)
			cout << coefficient[1] << "x";

		if(coefficient[0] > 0)
			cout << "+" << coefficient[0] << endl;
		else if(coefficient[0] < 0)
			cout << coefficient[0] << endl;
		return;
	}
	else if(degree == 0)
	{
		if(coefficient[0] > 0)
			cout << "+" << coefficient[0] << endl;
		else if(coefficient[0] < 0)
			cout << coefficient[0] << endl;
		return;
	}

	for(int i = degree - 2; i > 1; i--)
	{
		if(coefficient[i] == 1)
			cout << "+" << "x^" << i;
		else if(coefficient[i] > 1)
			cout << "+" << coefficient[i] << "x^" << i;
		else if(coefficient[i] < 0)
			cout << coefficient[i] << "x^" << i;
	}

	if(coefficient[1] == 1)
		cout << "+" << "x";
	else if(coefficient[1] > 1)
		cout << "+" << coefficient[1] << "x";
	else if(coefficient[1] < 0)
		cout << coefficient[1] << "x";

	if(coefficient[0] > 0)
		cout << "+" << coefficient[0];
	else if(coefficient[0] < 0)
		cout << coefficient[0];
	cout << endl;