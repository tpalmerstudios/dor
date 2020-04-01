string eyeString (char cColor)
{
		string sColor = "N/A";
		switch (cColor)
		{
				case 'G':
						sColor = "Green";
						break;
				case 'b':
						sColor = "Brown";
						break;
				case 'B':
						sColor = "Blue";
						break;
				case 'h':
						sColor = "Hazel";
						break;
				case 'a':
						sColor = "Amber";
						break;
				case 'g':
						sColor = "Gray";
						break;
				case 'r':
						sColor = "Red";
						break;
				default:
						sColor = "N/A";
		}
		return sColor;
}
string hairString (char cColor)
{
		string sColor = "N/A";
		switch (cColor)
		{
				case 'l':
						sColor = "Black";
						break;
				case 'w':
						sColor = "Brown";
						break;
				case 'o':
						sColor = "Blonde";
						break;
				case 'r':
						sColor = "Red";
						break;
				case 'g':
						sColor = "Gray";
						break;
				case 'w':
						sColor = "White";
						break;
				default:
						sColor = "N/A";
		}
		return sColor;
}
