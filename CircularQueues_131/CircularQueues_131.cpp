#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5]; 

public:
	Queues() {								
		FRONT = -1;										//step 1 ;set front = -1
		REAR = -1;										//set rear = -1
	}

	void insert() {
		int num;
		cout << "enter a number : ";
		cin >> num;
		cout << endl;


		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		//cek apakah antrian kosong
		if (FRONT == -1) {							//step 1
			FRONT = 0;								//step 1a
			REAR = 0;								//step 1b
		}
		else {
			//jika benar berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)					//step 2
				REAR = 0;							//step 2a
			else
				REAR = REAR + 1;					//step 3
		}
		queue_array[REAR] = num;					//step 4
	}

	void remove() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "queue underflow\n";
			return;
		}
		cout << "\nthe element deleted from the queue is :" << queue_array[FRONT] << "\n";

		//cek jika antrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen yg dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)				
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}
	void display() {
		int FRONT_POSITION = FRONT;
		int REAR_POSITION= REAR;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "queuenis empty\n";
				return;
		}

		cout << "\nelements in the queue are....\n";

		//jika FRONT_POSITION <= REAR_POSITiOn, iterasi dari FRONT hingga REAR
		if (FRONT_POSITION <= REAR_POSITION) {
			while (FRONT_POSITION <= REAR_POSITION) {
				cout << queue_array[FRONT_POSITION] << " ";
				FRONT_POSITION++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_POSITION > REAR_POSITION, iterasi dari FRONT hingga akhir array
			while (FRONT_POSITION <= max - 1) {
				cout << queue_array[FRONT_POSITION] << " ";
				FRONT_POSITION++;
			}

			FRONT_POSITION = 0;

			//iterasi dari awal array hingga REAR
			while (FRONT_POSITION <= REAR_POSITION) {
				cout << queue_array[FRONT_POSITION] << " ";
				FRONT_POSITION++;
			}
			cout << endl;
		}
	}
};

int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "menu" << endl;
			cout << "1. implement insert operation" << endl;
			cout << "2. implement delete operation" << endl;
			cout << "3. display values" << endl;
			cout << "4. exit" << endl; 
			cout << "enter your choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {
					q.insert();
					break;
				}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case'4': {
				return 0;
			}
			default: {
				cout << "invalid option!!" << endl;
				break;
			}
			}
		}
		catch (exception& a) {
			cout << "check for the values entered" << endl;
		}
	}

	return 0;
}