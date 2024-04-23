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
    cout << "Your MBTI type is :";
    // type = 0
    if ((fri[min_index[0]].type[0] == 'I' && fri[min_index[1]].type[0] == 'I') || (fri[min_index[0]].type[0] == 'E' && fri[min_index[1]].type[0] == 'E')){
        cout << fri[min_index[0]].type[0];
    }
    else if (fri[min_index[0]].type[2] != fri[min_index[1]].type[2]){
        cout << fri[min_index[2]].type[0];
    }
    //type = 1
    if ((fri[min_index[0]].type[1] == 'N' && fri[min_index[1]].type[1] == 'N') || (fri[min_index[0]].type[1] == 'S' && fri[min_index[1]].type[1] == 'S')){
        cout << fri[min_index[0]].type[1];
    }
    else if (fri[min_index[0]].type[1] != fri[min_index[1]].type[1]){
        cout << fri[min_index[2]].type[1];
    }
    //type = 2
    if ((fri[min_index[0]].type[2] == 'T' && fri[min_index[1]].type[2] == 'T') || (fri[min_index[0]].type[2] == 'F' && fri[min_index[1]].type[2] == 'F')){
        cout << fri[min_index[0]].type[2];
    }
    else if (fri[min_index[0]].type[2] != fri[min_index[1]].type[2]){
        cout << fri[min_index[2]].type[2];
    }
    //type = 3
    if ((fri[min_index[0]].type[3] == 'J' && fri[min_index[1]].type[3] == 'J') || (fri[min_index[0]].type[3] == 'P' && fri[min_index[1]].type[3] == 'P')){
        cout << fri[min_index[0]].type[3];
    }
    else if (fri[min_index[0]].type[3] != fri[min_index[1]].type[3]){
        cout << fri[min_index[2]].type[3];
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
    Data_friend[1] = {"chanatip kwaechaoon", 31.8, 33, 22, 30, 35, 26, 24, 23, "INTJ"};
    Data_friend[2] = {"Yodsaphat Kumwong", 12.8, 15.6, 14, 29, 21, 20, 17, 17, "ISTJ"};
    Data_friend[3] = {"Siwat Chotchong", 9.8, 14, 23, 23, 27, 30, 13, 25,"ISTP"};
    Data_friend[4] = {"Janthima Janhom", 27.4, 30.4, 25, 25, 33, 28, 29, 19, "ENFJ"};
    Data_friend[5] = {"Nitipoom Phramsrichai", 41.4, 31.8, 38, 42, 25, 36, 21, 39, "INTP"};
    Data_friend[6] = {"Surasan Phothichak", 29.4, 36.4, 30, 34, 26, 28, 35, 29, "INFJ"};
    Data_friend[7] = {"Tanyatorn Kongtonglang", 25.4, 20.4, 33, 30, 24, 32, 24, 17, "INFJ"};
    Data_friend[8] = {"Sorawich Hongsopa", 21.4, 20.4, 30, 31, 34, 30, 17, 22, "ISTP"};
    Data_friend[9] = {"Athitan Mahamon", 41, 30.4, 29, 45, 24, 42, 33, 31, "INTP"};
    Data_friend[10] = {"Nutgritta Prasomthongsuk ",37, 37.4, 37, 30, 28, 40, 35, 29, "ISTJ"};
    Data_friend[11] = {"Sittan Kunanit", 35.8, 35.6, 18, 23, 17, 32, 26, 22, "INFJ"};
    Data_friend[12] = {"Jiratchaya Suwancheewasiri", 28.6, 21, 23, 24, 22, 26, 26, 13, "ENTP"};
    Data_friend[13] = {"Teerapan Lueangkittikong", 29.4,39.4,34,42,32,31,29,29, "INTJ"};
    Data_friend[14] = {"Anukool Baiban", 39.2, 34.6, 30, 23, 25, 28, 36, 23, "ENFJ"};
    Data_friend[15] = {"Natthinan Kerdsri", 30, 18.4, 19, 31, 25, 31, 25, 15, "INTP"};
    Data_friend[16] = {"Watcharin Tadajetsombat", 22.8, 27, 31, 33, 29, 35, 26, 22, "ISTJ"};
    Data_friend[17] = {"Sukumpat Rujitanatroj", 21.8, 26, 21, 34, 26, 25, 23, 22, "ISTP"};
    Data_friend[18] = {"Panwad Kabucha", 30.4, 38, 20, 30, 18, 29, 24, 14, "INFJ"};
    Data_friend[19] = {"nutthawarara Sasrimuang", 29.4, 28.6, 30, 31, 31, 34, 27, 25, "ISTJ"};
    Data_friend[20] = {"Tonyok Buranawanich", 18.4, 26.6, 33, 38, 23, 41, 20, 24, "ISTJ"};
    Data_friend[21] = {"Mongkud Wathanasilapakit", 21, 29.4, 23, 36, 26, 32, 16, 27, "ISTP"};
    Data_friend[22] = {"Natthapol Premkamon", 25.4, 26, 18, 28, 25, 23, 19, 23, "ISTP"};
    Data_friend[23] = {"Amy Suganya Tripp", 20, 14.8, 31, 37, 33, 17, 24, 27, "ESTP"};
    Data_friend[24] = {"Nichanun Boontanom", 24.2, 25.6, 21, 26, 23, 28, 15, 21, "ISTP"};
    /*
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
    */
    //Data_me[0] = {"Narutchai Mauensaen", 33.2, 27, 32, 28, 33, 32, 39, 40, ""};
    Data_me = {"Narutchai Mauensaen", 33.2, 27, 32, 28, 33, 32, 39, 40, ""}; // ข้อมูลของคุณ

    knn(Data_friend, Data_me);
    return 0;
}