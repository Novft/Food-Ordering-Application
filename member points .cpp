#include<iostream>

using namespace std;

int main() {

	double payment = 0, points, topp, getp;
	
	char count1 = 0, cancel, upp, wtup;
	const int magnification = 10;

	//take payment
	cout << "payment";
	cin >> payment; cout << endl;
	//take points data
	cout << "points";
	cin >> points[chosen_position]; cout << endl;
	//take topp date
	cout << "topp";
	cin >> topp; cout << endl;


	if (payment <= points[chosen_position]) {

		cout << "-------------------------------------------------------------------------" << endl;
		cout << "DO you want use points pay ?(Y/N)" << endl;
		cout << "you points          : " << points[chosen_position] << endl;
		cout << "you need payment RM : " << payment << endl;
		getp = payment * magnification;
		cout << "you will get        : " << getp << " points" << endl;
		cout << "Enter you choose    : ";
		cin >> count1;

		if (count1 == 'y' || count1 == 'Y')
		{
			cout << "-------------------------------------------------------------------------" << endl;
			points[chosen_position] = points[chosen_position] - payment;

			cout << "Payment completed " << endl;
			cout << "Remaning points : " << points[chosen_position] << endl;
			cout << "Get Points      : " << getp << endl;
			points[chosen_position] = points[chosen_position] = getp;
			cout << "Now has Points  : " << points[chosen_position] << endl;
			//update points
			//return (home)

		}
		else if (count1 == 'n' || count1 == 'N')
		{
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "you choose use top up point payment" << endl;


			cout << "-------------------------------------------------------------------------" << endl;
			cout << "yout points insufficient !!! Now use top up points payment " << endl;
			cout << "you top up points : " << topp << endl;
			cout << "you need payment  : " << payment << endl;
			getp = payment * magnification;
			cout << "you will get      : " << getp << " points" << endl;

			if (topp >= payment)
			{

				cout << "-------------------------------------------------------------------------" << endl;
				topp = topp - payment;

				cout << "Payment completed " << endl;
				cout << "Remaning points : " << topp << endl;
				cout << "Get Points      : " << getp << endl;
				points[chosen_position] = points[chosen_position] = getp;
				cout << "Now has Points  : " << points[chosen_position] << endl;

				//updata topp and points
				if (topp < 20) {

					cout << "your topup points less 20 , do you want to topup points?[Y/N]" << endl;
					cin >> wtup;
					if (wtup == 'y' || wtup == 'Y') {
						cout << "test want to top up" << endl;
						//goto top up modelu
					}
					else if (wtup == 'n' || wtup == 'N') {
						cout << "test n";
						//return(home)
					}
				}


				//return(home)
			}
			else {
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "your top up points insufficient !!!" << endl;
				cout << "want to top up points(Y/N)" << endl;
				cin >> upp;

				if (upp == 'y' || upp == 'Y') {
					cout << "-------------------------------------------------------------------------" << endl;
					cout << "goto topUp point " << endl;
					//return (topuppoints)

				}
				else if (upp == 'n' || upp == 'N') {
					cout << "-------------------------------------------------------------------------" << endl;
					cout << "sorry you need top up point for payment " << endl;
					cout << "if you want cancel payment -----Press[C]" << endl;
					cout << "goto topUp point-----Press[T] " << endl;
					cin >> cancel;
					if (cancel == 'c' || cancel == 'C') {
						cout << "testC" << endl;
						//return (payment module)
					}
					else if (cancel == 't' || cancel == 'T') {
						cout << "testT" << endl;
						//return (topuppoint)
					}

				}
			}


		}
	}






	else {
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "yout points insufficient !!! Now use top up points payment " << endl;
		cout << "you top up points : " << topp << endl;
		cout << "you need payment  : " << payment << endl;
		getp = payment * magnification;
		cout << "you will get      : " << getp << " points" << endl;

		if (topp >= payment)
		{

			cout << "-------------------------------------------------------------------------" << endl;
			topp = topp - payment;

			cout << "Payment completed " << endl;
			cout << "Remaning points : " << topp << endl;
			cout << "Get Points      : " << getp << endl;
			points = points = getp;
			cout << "Now has Points  : " << points << endl;

			//updata topp and points
			if (topp < 20) {

				cout << "your topup points less 20 , do you want to topup points?[Y/N]" << endl;
				cin >> wtup;
				if (wtup == 'y' || wtup == 'Y') {
					cout << "test want to top up" << endl;
					//goto top up modelu
				}
				else if (wtup == 'n' || wtup == 'N') {
					cout << "test n";
					//return(home)
				}
			}


			//return(home)
		}
		else {
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "your top up points insufficient !!!" << endl;
			cout << "want to top up points(Y/N)" << endl;
			cin >> upp;

			if (upp == 'y' || upp == 'Y') {
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "goto topUp point " << endl;
				//return (topuppoints)

			}
			else if (upp == 'n' || upp == 'N') {
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "sorry you need top up point for payment " << endl;
				cout << "if you want cancel payment -----Press[C]" << endl;
				cout << "goto topUp point-----Press[T] " << endl;
				cin >> cancel;
				if (cancel == 'c' || cancel == 'C') {
					cout << "testC" << endl;
					//return (payment module)
				}
				else if (cancel == 't' || cancel == 'T') {
					cout << "testT" << endl;
					//return (topuppoint)
				}

			}
		}
	}
}
