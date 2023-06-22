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
	}
};