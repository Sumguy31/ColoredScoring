#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

enum color { Orange, Purple, Blue };

class riser {
	public:

	color color = Orange;
	double start_cord[2] = { 0,0 };
	double end_cord[2] = { 0,0 };

	int zoneAssignment = 0;

	double distTravel() {
		double x_sq = (end_cord[0] - start_cord[0]) * (end_cord[0] - start_cord[0]);
		double y_sq = (end_cord[1] - start_cord[1]) * (end_cord[1] - start_cord[1]);
		return sqrt(x_sq + y_sq);	
	}
	double distance(double x_end, double y_end) {
		double x_sq = (x_end - start_cord[0]) * (x_end - start_cord[0]);
		double y_sq = (y_end - start_cord[1]) * (y_end - start_cord[1]);
		return sqrt(x_sq + y_sq);
	}
};

class zone{
	public:
	color color = Orange;
	double cord[2] = { 0,0 };
	int row = 0;
	int col = 0;
	int riserCount = 0;
};

//Name Declarations for Zones and Risers

zone zone_1;
zone zone_2;
zone zone_3;
zone zone_4;
zone zone_5;
zone zone_6;
zone zone_7;
zone zone_8;
zone zone_9;

riser riser_1;
riser riser_2;
riser riser_3;
riser riser_4;
riser riser_5;
riser riser_6;
riser riser_7;
riser riser_8;
riser riser_9;
riser riser_10;
riser riser_11;
riser riser_12;
riser riser_13;
riser riser_14;
riser riser_15;
riser riser_16;
riser riser_17;
riser riser_18;
riser riser_19;
riser riser_20;
riser riser_21;
riser riser_22;
riser riser_23;
riser riser_24;
riser riser_25;
riser riser_26;
riser riser_27;

zone zoneList[9] = { zone_1,zone_2,zone_3,zone_4,zone_5,zone_6,zone_7,zone_8,zone_9 };
riser riserArray[27] = { riser_1,riser_2,riser_3,riser_4,riser_5,riser_6,riser_7,riser_8,riser_9,riser_10,
						riser_11,riser_12,riser_13,riser_14,riser_15,riser_16,riser_17,riser_18,riser_19,riser_20,
						riser_21,riser_22,riser_23,riser_24,riser_25,riser_26,riser_27
};
color colorArray[6][3]{
	{Orange, Purple, Blue},
	{Orange, Blue, Purple},
	{Purple, Orange, Blue},
	{Purple, Blue, Orange},
	{Blue, Orange, Purple},
	{Blue, Purple, Orange}
};

void declareZone(){
	zoneList[0].cord[0] = 1;
	zoneList[0].cord[1] = 1;
	zoneList[0].row = 1;
	zoneList[0].col = 1;
		
	zoneList[1].cord[0] = 8;
	zoneList[1].cord[1] = 1;
	zoneList[1].row = 1;
	zoneList[1].col = 2;
		
	zoneList[2].cord[0] = 15;
	zoneList[2].cord[1] = 1;
	zoneList[2].row = 1;
	zoneList[2].col = 3;
		
	zoneList[3].cord[0] = 1;
	zoneList[3].cord[1] = 6;
	zoneList[3].row = 2;
	zoneList[3].col = 1;
		
	zoneList[4].cord[0] = 8;
	zoneList[4].cord[1] = 6;
	zoneList[4].row = 2;
	zoneList[4].col = 2;
		
	zoneList[5].cord[0] = 15;
	zoneList[5].cord[1] = 6;
	zoneList[5].row = 2;
	zoneList[5].col = 3;
		
	zoneList[6].cord[0] = 1;
	zoneList[6].cord[1] = 11;
	zoneList[6].row = 3;
	zoneList[6].col = 1;
		
	zoneList[7].cord[0] = 8;
	zoneList[7].cord[1] = 11;
	zoneList[7].row = 3;
	zoneList[7].col = 2;
		
	zoneList[8].cord[0] = 15;
	zoneList[8].cord[1] = 11;
	zoneList[8].row = 3;
	zoneList[8].col = 3;
};

void declareOrange() {
	riserArray[0].start_cord[1] = 1;
	riserArray[0].start_cord[0] = 3;
	
	riserArray[1].start_cord[0] = 7;
	riserArray[1].start_cord[1] = 1;
	
	riserArray[3].start_cord[1] = 1;
	riserArray[3].start_cord[0] = 13;

	riserArray[9].start_cord[1] = 4;
	riserArray[9].start_cord[0] = 6;
	
	riserArray[10].start_cord[0] = 10;
	riserArray[10].start_cord[1] = 4;

	riserArray[19].start_cord[0] = 3;
	riserArray[19].start_cord[1] = 7;
		
	riserArray[20].start_cord[0] = 13;
	riserArray[20].start_cord[1] = 7;

	riserArray[22].start_cord[0] = 3;
	riserArray[22].start_cord[1] = 9;

	riserArray[23].start_cord[0] = 13;
	riserArray[23].start_cord[1] = 9;
}
void declarePurple() {
	riserArray[4].start_cord[0] = 8;
	riserArray[4].start_cord[1] = 2;
		 
	riserArray[5].start_cord[0] = 1;
	riserArray[5].start_cord[1] = 3;

	riserArray[8].start_cord[0] = 15;
	riserArray[8].start_cord[1] = 3;

	riserArray[11].start_cord[0] = 3;
	riserArray[11].start_cord[1] = 5;

	riserArray[14].start_cord[0] = 13;
	riserArray[14].start_cord[1] = 5;
	
	riserArray[16].start_cord[0] = 6;
	riserArray[16].start_cord[1] = 6;

	riserArray[17].start_cord[0] = 10;
	riserArray[17].start_cord[1] = 6;

	riserArray[21].start_cord[0] = 1;
	riserArray[21].start_cord[1] = 9;

	riserArray[24].start_cord[0] = 15;
	riserArray[24].start_cord[1] = 9;
}
void declareBlue() {
	riserArray[2].start_cord[0] = 9;
	riserArray[2].start_cord[1] = 1;
		 
	riserArray[6].start_cord[0] = 3;
	riserArray[6].start_cord[1] = 3;
		 
	riserArray[7].start_cord[0] = 13;
	riserArray[7].start_cord[1] = 3;
		 
	riserArray[12].start_cord[0] = 6;
	riserArray[12].start_cord[1] = 5;
		 
	riserArray[13].start_cord[0] = 10;
	riserArray[13].start_cord[1] = 5;
		 
	riserArray[15].start_cord[0] = 4;
	riserArray[15].start_cord[1] = 6;
		 
	riserArray[18].start_cord[0] = 12;
	riserArray[18].start_cord[1] = 6;
		 
	riserArray[25].start_cord[0] = 3;
	riserArray[25].start_cord[1] = 11;
		 
	riserArray[26].start_cord[0] = 13;
	riserArray[26].start_cord[1] = 11;
}

void declareRiser() {
	riserArray[0].color = Orange;
	riserArray[1].color = Orange;
	riserArray[2].color = Blue;
	riserArray[3].color = Orange;
	riserArray[4].color = Purple;
	riserArray[5].color = Purple;
	riserArray[6].color = Blue;
	riserArray[7].color = Blue;
	riserArray[8].color = Purple;
	riserArray[9].color = Orange;
	riserArray[10].color = Orange;
	riserArray[11].color = Purple;
	riserArray[12].color = Blue;
	riserArray[13].color = Blue;
	riserArray[14].color = Purple;
	riserArray[15].color = Blue;
	riserArray[16].color = Purple;
	riserArray[17].color = Purple;
	riserArray[18].color = Blue;
	riserArray[19].color = Orange;
	riserArray[20].color = Orange;
	riserArray[21].color = Purple;
	riserArray[22].color = Orange;
	riserArray[23].color = Orange;
	riserArray[24].color = Purple;
	riserArray[25].color = Blue;
	riserArray[26].color = Blue;
	declareOrange();
	declareBlue();
	declarePurple();
}

double inchesToCordUnit(double inches) {
	return 0;
}

void rowColors(int frow, color fcolor) {
	for (int i = 0; i < 9; i++) {
		if (zoneList[i].row == frow) {
			zoneList[i].color = fcolor;
		}
	}
}

void colColors(int fcol, color fcolor) {
	for (int i = 0; i < 9; i++) {
		if (zoneList[i].col == fcol) {
			zoneList[i].color = fcolor;
		}
	}
}
void resetZoneAssignments() {
	for (int i = 0; i < 27; i++) {
		riserArray[i].zoneAssignment = 0;
	}
	for (int i = 0; i < 9; i++) {
		zoneList[i].riserCount = 0;
	}
}
void assignZone() {
	resetZoneAssignments();
	for (int i = 0; i < 27; i++) {//parse through risers
		int minIndex  = 0;
		double minDist = 999;
		int currIndex = 0;
		double currDist = 0;
		for (int j = 0; j < 9; j++) {//parse through zones
			if (riserArray[i].color == zoneList[j].color) {//check color match
				currIndex = j;
				currDist = riserArray[i].distance(zoneList[j].cord[0], zoneList[j].cord[1]);//check distance
				
				if (currDist < minDist) {//check for least distance
					minDist = currDist;
					minIndex = currIndex;					
				}
			}
		}

		riserArray[i].zoneAssignment = minIndex + 1; //store values
		riserArray[i].end_cord[0] = zoneList[minIndex].cord[0];
		riserArray[i].end_cord[1] = zoneList[minIndex].cord[1];

		zoneList[minIndex].riserCount += 1;
	}
	for (int i = 0; i < 9; i++) {
		if (zoneList[i].riserCount > 3) {
			cout << "Warning! Zone ";
			cout << i + 1;
			cout << " has ";
			cout << zoneList[i].riserCount;
			cout << " risers\n";
		}
	}
}

double getTotalDist() {
	double total = 0;
	for (int i = 0; i < 26; i++) {
		total += riserArray[i].distTravel();
	}
	return total;
}


void createDistCSV() {
	std::ofstream myFile("dist.csv");
	myFile << " ,";
	for (int i = 0; i < 9; i++) {
		myFile << "Zone #";
		myFile << i+1;
		myFile << ',';
	}
	myFile << "\n";
	for (int i = 0; i < 27; i++) {
		myFile << "Riser #";
		myFile << i+1;
		myFile << ',';
		for (int j = 0; j < 9; j++) {
			riserArray[i].end_cord[0] = zoneList[j].cord[0];
			riserArray[i].end_cord[1] = zoneList[j].cord[1];

			myFile << riserArray[i].distTravel();
			myFile << ",";
		}
		myFile << "\n";
		cout << "row ";
		cout << i;
		cout << " complete\n";
	}

	myFile.close();
}
void createZoneCSV() {
	std::ofstream fZone("zoneCoordinate.csv");
	for (int i = 0; i < 9; i++) {
		fZone << zoneList[i].cord[0];
		fZone << ',';
		fZone << zoneList[i].cord[1];
		fZone << "\n";
	}
}
void createRiserCSV() {
	std::ofstream fRiser("riserCoordinate.csv");
	for (int i = 0; i < 27; i++) {
		fRiser << riserArray[i].start_cord[0];
		fRiser << ',';
		fRiser << riserArray[i].start_cord[1];
		fRiser << ',';
		fRiser << riserArray[i].color;
		fRiser << "\n";
	}
}
int main() {
	declareZone();
	declareRiser();

	createZoneCSV();
	createRiserCSV();
	
	//std::ofstream fRows("rowZone.csv");
	//cout << "Starting Rows";
	//cout << "\n ---------------------------- \n \n";
	//for (int i = 0; i < 6; i++) {
	//	
	//	for (int j = 0; j < 3; j++) {
	//		rowColors(j+1, colorArray[i][j]);
	//	}
	//	assignZone();
	//	for (int j = 0; j < 27; j++) {
	//		fRows << riserArray[j].zoneAssignment;
	//		fRows << ',';
	//	}
	//	fRows << "\n";

	//	cout << "Total Distance: ";
	//	cout << getTotalDist();
	//	cout << "\n ---------------------------- \n \n";
	//}
	//fRows.close();

	//std::ofstream fCols("colZone.csv");
	//cout << "Starting Columns";
	//cout << "\n ---------------------------- \n \n";
	//for (int i = 0; i < 6; i++) {

	//	for (int j = 0; j < 3; j++) {
	//		colColors(j + 1, colorArray[i][j]);
	//	}
	//	assignZone();
	//	for (int j = 0; j < 27; j++) {
	//		fCols << riserArray[j].zoneAssignment;
	//		fCols << ',';
	//	}
	//	fCols << "\n";

	//	cout << "Total Distance: ";
	//	cout << getTotalDist();
	//	cout << "\n ---------------------------- \n \n";
	//}
	//fCols.close();
};