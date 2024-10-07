#include <iostream>
using namespace std;

const int NUM_USERS = 3; 
const int NUM_ITEMS = 3; 

void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        cout << "사용자" << (i + 1) << "의 선호도를 입력하세요 (" << NUM_ITEMS << "개의 항목에 대해 ): ";
        for (int j = 0; j < NUM_ITEMS; ++j) {
            cout << "항목 " << (j + 1) << ": ";
            cin >> preferences[i][j];
        }
    }
}


void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        int maxPreference = preferences[i][0]; 
        int count = 1; 
        int maxPreferenceIndex = 0; 

        
        for (int j = 1; j < NUM_ITEMS; ++j) {
            if (preferences[i][j] > maxPreference) {
                maxPreference = preferences[i][j];
                maxPreferenceIndex = j; 
                count = 1;
            } else if (preferences[i][j] == maxPreference) {
                count++; 
            }
        }

       
        int randomIndex = maxPreferenceIndex;
        if (count > 1) {
           
            int randomOffset = rand() % count;
            
            int tieIndices[NUM_ITEMS];
            int tieCount = 0;

            
            for (int j = 0; j < NUM_ITEMS; ++j) {
                if (preferences[i][j] == maxPreference) {
                    tieIndices[tieCount++] = j;
                }
            }
            randomIndex = tieIndices[randomOffset]; 
        }

        cout << "사용자" << (i + 1) << "에게 추천하는 항목: " << (randomIndex + 1) << endl;
    }
}

int main() {
    int userPreferences[NUM_USERS][NUM_ITEMS]; 

    initializePreferences(userPreferences); 
    findRecommendedItems(userPreferences); 

    return 0;
}
