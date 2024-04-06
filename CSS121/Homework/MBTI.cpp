#include <iostream>
#include <cmath>
using namespace std;

struct userData {
    string name;
    float Ne, Ni, Te, Ti, Se, Si, Fe, Fi;
    string type;
};

void knn(userData* fri, userData me) {
    int size = 50, min_index[3],I = 0, E = 0, S = 0, N = 0, T = 0, F = 0, J = 0, P = 0;
    float lowdistance[3] = {9999, 9999, 9999};
    float distance[size];
    for (int i = 0; i < size; i++) {
        distance[i] = sqrt(pow(fri[i].Ne - me.Ne, 2) + pow(fri[i].Ni - me.Ni, 2) + pow(fri[i].Te - me.Te, 2) + pow(fri[i].Ti - me.Ti, 2) + pow(fri[i].Se - me.Se, 2) + pow(fri[i].Si - me.Si, 2) + pow(fri[i].Fe - me.Fe, 2) + pow(fri[i].Fi - me.Fi, 2));
        if (distance[i] < lowdistance[0] || distance[i] < lowdistance[1] || distance[i] < lowdistance[2]) {
            if (distance[i] <= lowdistance[0]) {
                lowdistance[2] = lowdistance[1];
                lowdistance[1] = lowdistance[0];
                lowdistance[0] = distance[i];
                min_index[0] = i;
            } else if (distance[i] <= lowdistance[1]) {
                lowdistance[2] = lowdistance[1];
                lowdistance[1] = distance[i];
                min_index[1] = i;
            } else {
                lowdistance[2] = distance[i];
                min_index[2] = i;
            }
        }
    }
    if (fri[min_index[0]].type[0] == 'I') {
        I++;
    } else {
        E++;
    }
    if (fri[min_index[0]].type[1] == 'N') {
        N++;
    } else {
        S++;
    }
    if (fri[min_index[0]].type[2] == 'T') {
        T++;
    } else {
        F++;
    }
    if (fri[min_index[0]].type[3] == 'J') {
        J++;
    } else {
        P++;
    }
    /////////////////////////////////////////////////////////////////
    if (fri[min_index[1]].type[0] == 'I') {
        I++;
    } else {
        E++;
    }
    if (fri[min_index[1]].type[1] == 'N') {
        N++;
    } else {
        S++;
    }
    if (fri[min_index[1]].type[2] == 'T') {
        T++;
    } else {
        F++;
    }
    if (fri[min_index[1]].type[3] == 'J') {
        J++;
    } else {
        P++;
    }
    ////////////////////////////////////////////////////////////////
    if (fri[min_index[2]].type[0] == 'I') {
        I++;
    } else {
        E++;
    }
    if (fri[min_index[2]].type[1] == 'N') {
        N++;
    } else {
        S++;
    }
    if (fri[min_index[2]].type[2] == 'T') {
        T++;
    } else {
        F++;
    }
    if (fri[min_index[2]].type[3] == 'J') {
        J++;
    } else {
        P++;
    }
    ///////////////////////////////////////////////////////////////
    cout << "Your MBTI type : ";
    if (I > E) {
        cout << "I";
    } else {
        cout << "E";
    }
    if (N > S) {
        cout << "N";
    } else {
        cout << "S";
    }
    if (T > F) {
        cout << "T";
    } else {
        cout << "F";
    }
    if (P > J) {
        cout << "P";
    } else {
        cout << "J";
    }
    cout << "\nThe 3 Nearest Neighbors is :" << endl << fri[min_index[0]].name << "Type :" << fri[min_index[0]].type << endl;
    cout << fri[min_index[1]].name << "Type :" << fri[min_index[1]].type << endl;
    cout << fri[min_index[2]].name << "Type :" << fri[min_index[2]].type;
}
int main() {
    int size = 50;
    userData Data_friend[size];
    userData Data_me;

    Data_friend[0] = {"Warin Wattanapornprom", 32, 32, 27, 36, 29, 31, 28, 23, "INTP"};
    Data_friend[1] = {"Kornkanok Welagert", 28.4, 29.4, 29, 34, 27, 24, 23, 21, "ISTP"};
    Data_friend[2] = {"Kritamet Chongcharoen", 22.4, 21.2, 20, 27, 21, 30, 17, 21, "INTP"};
    Data_friend[3] = {"Kunakron Tana", 30, 24, 25, 27, 23, 28, 26, 17, "ENTP"};
    Data_friend[4] = {"Chinavat Nachaithong", 35.6, 37.8, 27, 28, 28, 29, 36, 35, "ENFP"};
    Data_friend[5] = {"Teekamon Chaiwongwutikul", 23.4, 26, 27, 30, 28, 31, 26, 21, "ISTJ"};
    Data_friend[6] = {"Dollatham Charoethammkic", 37, 47.8, 43, 47, 47, 45, 37, 43, "INTJ"};
    Data_friend[7] = {"Thiyada Kittiwithitkun", 34, 26.6, 26, 29, 28, 34, 33, 32, "ESFJ"};
    Data_friend[8] = {"Thidarat Sitthidech", 29, 31.2, 26, 27, 17, 32, 33, 26, "INFJ"};
    Data_friend[9] = {"Phumiphat Santithawornying", 26.2, 28.6, 21, 25, 30, 31, 32, 20, "INFJ"};
    Data_friend[10] = {"Manotham Damnoen", 35.4, 29.4, 26, 28, 28, 19, 29, 27, "ENTP"};
    Data_friend[11] = {"Wachirawit Intapan", 29, 25, 21, 23, 32, 36, 14, 19, "INTP"};
    Data_friend[12] = {"Warit Teerapong", 35.8, 28.4, 28, 32, 18, 32, 31, 35, "INFP"};
    Data_friend[13] = {"Sasima Phanta", 20.4, 22.4, 32, 32, 24, 28, 25, 16, "ESTJ"};
    Data_friend[14] = {"Artima Rojanagamonson", 34.8, 28, 35, 32, 26, 32, 28, 17, "ESTJ"};
    Data_friend[15] = {"Koraphan Manitha", 22.4, 31.4, 33, 34, 33, 35, 25, 23, "INTP"};
    Data_friend[16] = {"Ganyawee Sanghom", 34.4, 36.8, 24, 32, 28, 35, 32, 34, "INFP"};
    Data_friend[17] = {"Kimhan Jongjaidee", 38.2, 32.2, 35, 34, 17, 28, 28, 18, "ENTP"};
    Data_friend[18] = {"Chaithawat Saklang", 24.8, 24.6, 29, 26, 29, 28, 29, 29, "ESFP"};
    Data_friend[19] = {"Nattanischa Aumpornchairuch", 29.2, 23.8, 28, 30, 22, 31, 32, 21, "ESTJ"};
    Data_friend[20] = {"Thanapong Simmanee", 23.4, 30.8, 35, 41, 31, 36, 39, 29, "ISFJ"};
    Data_friend[21] = {"Thidarut Deeramies", 31.6, 36.4, 24, 32, 32, 30, 24, 20, "ISTP"};
    Data_friend[22] = {"Panachai Suvimolopas", 34.2, 24.6, 31, 35, 33, 25, 32, 25, "ENTP"};
    Data_friend[23] = {"Pattanapol Saelim", 41.8, 37.8, 28, 21, 34, 34, 33, 23, "ENTP"};
    Data_friend[24] = {"Pichayut Sombat", 32.2, 25.2, 29, 27, 30, 31, 25, 26, "INTP"};
    Data_friend[25] = {"Poomthai Promkote", 39.6, 46.8, 33, 36, 32, 36, 30, 30, "INTP"};
    Data_friend[26] = {"Lalhada Suttiprapha", 27.8, 23.4, 21, 27, 24, 35, 26, 22, "ISFJ"};
    Data_friend[27] = {"Santijit Kamnak", 22.4, 20.6, 26, 26, 26, 30, 22, 25, "ISTJ"};
    Data_friend[28] = {"Kantinan Kuikeaw", 13.8, 16, 33, 31, 35, 32, 23, 16, "ESTJ"};
    Data_friend[29] = {"Chothanin Thitisrirat", 29.8, 28, 24, 26, 29, 32, 36, 18, "ESFJ"};
    Data_friend[30] = {"Warin Wattanapornprom", 32, 32, 27, 36, 29, 31, 28, 23, "INTP"};
    Data_friend[31] = {"Yanisa Mungkarotai", 23, 26.6, 28, 25, 17, 29, 29, 31, "INTJ"};
    Data_friend[32] = {"Jessada Pranee", 27.8, 24.2, 32, 29, 18, 20, 13, 31, "INTP"};
    Data_friend[33] = {"Suphanut Chanroong", 34.6, 32, 25, 29, 23, 24, 29, 26, "ENFP"};
    Data_friend[34] = {"Keerataphan Malai", 15.6, 28.2, 21, 31, 19, 28, 18, 23, "ISTP"};
    Data_friend[35] = {"Thanachot Wongyai", 24.8, 19.2, 25, 30, 22, 28, 19, 25, "INTP"};
    Data_friend[36] = {"Pawinnarut Pornpanarat", 47.4, 31.2, 36, 32, 36, 37, 29, 31, "ENTP"};
    Data_friend[37] = {"Phirada Chemmanmud", 23.6, 22.2, 28, 35, 27, 40, 23, 22, "ISTJ"};
    Data_friend[38] = {"Phattawee Witthayapanyanont", 37.2, 23.6, 36, 39, 34, 33, 31, 16, "INTP"};
    Data_friend[39] = {"Sathapana Tinop", 23.2, 30.6, 30, 36, 19, 21, 4, 28, "INTP"};
    Data_friend[40] = {"Nuttasit Tannitipaisal", 33.6, 34.4, 24, 24, 31, 35, 32, 25, "ENTP"};
    Data_friend[41] = {"Nut Somwang", 19.6, 19.2, 25, 32, 36, 30, 20, 17, "ESTJ"};
    Data_friend[42] = {"Pattarachanon Uraiwichaikul", 35.6, 28.4, 36, 38, 36, 28, 29, 30, "ESTJ"};
    Data_friend[43] = {"Pattarapong Srisawat", 32.4, 28.4, 32, 32, 28, 28, 28, 28, "ENTP"};
    Data_friend[44] = {"Krantharat Ratchart", 26.6, 21, 27, 27, 25, 26, 22, 19, "ESTJ"};
    Data_friend[45] = {"Pasin Laopooti", 32.8, 31, 28, 37, 29, 38, 25, 29, "INTP"};
    Data_friend[46] = {"Patchnida Hemwannanukul", 29.8, 23.4, 30, 26, 27, 30, 29, 29, "ESTJ"};
    Data_friend[47] = {"Nakamon Yongpaisarn", 28, 24, 31, 31, 29, 37, 28, 28, "INFP"};
    Data_friend[48] = {"Natthapon Tanateeraanan", 24.6, 22, 32, 32, 36, 38, 35, 27, "ESTP"};
    Data_friend[49] = {"Naphatchanun Suecey",23.4, 26, 31, 33, 24, 27, 31, 21, "ESFJ"};
    //Data_me[0] = {"Narutchai Mauensaen", 33.2, 27, 32, 28, 33, 32, 39, 40, ""};
    Data_me = {"Narutchai Mauensaen", 33.2, 27, 32, 28, 33, 32, 39, 40, ""}; // ข้อมูลของคุณ

    knn(Data_friend, Data_me);
    return 0;
}
