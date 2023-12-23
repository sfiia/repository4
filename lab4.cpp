#include <iostream>
#include <fstream>

using namespace std;
int line_down_times;
int const wordsLen = 10, startWords = 50;
char symbols[] = {'!', ',', ' ',
                  '?', ':', ';',
                  '-', };

char first_10_of_Latin[] = {'A', 'B', 'C', 'D', 'E',
                            'F', 'G', 'H', 'I', 'J'};



void clearStream(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void readFile(char filename[], char string[]){
    ofstream fout;
    ifstream fin;
    char c;
    int n = 0;
    fin.open(filename);
    while (fin.get(c)){
        string[n] = c;
        ++n;
    }
    string[n] = '\0';
}


inline void lineDown(int times=1){
    for(line_down_times = 0; line_down_times < times; line_down_times++){
        cout << "\n";
    }
}


//----------------------------------------------------------------------------------------------------------------------
//string methods

int count(char string[], char symbol){
    int count = 0;
    for ( int i = 0; i < strlen(string); i++ ){
        if ( string[i] == symbol ) {
            count ++;
        }
    }

    return count;
}

int find(char string[], char symbol, int start=0){
    for (int index = start; index < strlen(string); index++){
        if (string[index] == symbol){
            return index;
        }
    }
    return -1;
}

int split(char string[], char splittedString[startWords][wordsLen], char separator=' '){
    int words = count(string, separator) + 1;
    int start, end = -1;
    for ( int i = 0; i < words; i++ ){
        start = end + 1;
        end = find(string, separator, start);
        if (end == -1){
            end = strlen(string);
        }
        for ( int j = start, index = 0; j < end; j++, index++ ){
            splittedString[i][index] = string[j];
        }

    }
    return words;

}


bool isPunct(char string[]){

    for ( int i = 0; i < strlen(symbols); i++ ){
        if (string[0] == symbols[i]){
            return true;
        }
    }
    return false;
}


void deleteSymbols(char string[], char symbol){
    for (int i = 0; i < strlen(string) - 1; i++){
        if (string[i] == symbol &&  string[i + 1] == symbol){

            for (int j = i + 1; j < strlen(string); j ++){
                string[j - 1] = string[j];
            }
            string[strlen(string) - 1] = '\0';
            i--;
        }
    }
}


int findSubstringsAmount(char string[], char substring[]) {
    bool flag;
    for ( int i = 0; i < strlen(string) - strlen(substring) - 1; i++ ){
        flag = true;
        for ( int j = 0; j < strlen(substring); j++ ){

        }
    }
    return 0;
}


void strWithoutDigs(char string[]){
    char digs[] = {'0', '1', '2', '3',
                   '4', '5', '6', '7',
                   '8', '9'};
    for (int i = 0; i < strlen(string); i++){
        for (int j = 0; j < 10; j++){
            if ( string[i] == digs[j] ){
                string[i] = ' ';
            }
        }
    }
}


void verticalcout(char string[]){
    for(int i = 0 ; i < strlen(string); i++){
        cout << string[i] << "\n";
    }
}

void changeRegistr(char string[]){

    for ( int i = 1; i < strlen(string); i++ ){
        string[i] = tolower(string[i]);

    }
    string[0] = toupper(string[0]);

}


int main() {
    int numZ, method;
    char filename[500];
    int const string_size = 500;
    char string[string_size], substring[string_size];
    bool repeaters;
    int words;
    char splittedString[startWords][wordsLen] = {};

    cout << "1. Ввести последовательность символов\n";
    cout << "2. Отредактировать входной текст\n";
    cout << "3. Ввести последовательность символов без цифр\n";
    cout << "4. Ввести последовательность символов вертикально\n";
    cout << "5. Найти все подстроки\n";

    for (int repeat = 0; repeat < 100; repeat++){
        cout << "\nВведите номер задания: \n";
        cin >> numZ;
        clearStream();

        switch (numZ){
            case 1:
                cout << "Выберите способ ввода последовательности(1. Ввод, 2. Файл): ";
                cin >> method;
                clearStream();

                if (method == 1){
                    cout << "Введите строку: \n";
                    cin.getline(string, string_size);
                }else{
                    cout << "Введите путь к файлу: \n";
                    cin.getline(filename, 500);
                    readFile(filename, string);
                }

                cout << "Введенная последовательность: \n";
                cout << string;
                break;

            case 2:
                for ( int i = 0; i < strlen(symbols); i++ ){
                    deleteSymbols(string, symbols[i]);
                }
                changeRegistr(string);

                cout << "Отформатированная строка: \n" << string;
                break;

            case 3:
                //№3
                cout << "Последовательности без цифр: \n";
                strWithoutDigs(string);
                deleteSymbols(string, ' ');
                cout << string;
                break;

            case 4:
                //№6
                cout << "Вывод последовательности вертикально: \n";
                verticalcout(string);
                cout << string;
                break;

            case 5:

                cout << "Введите подстроку: \n";
                cin.getline(string, string_size);
                cout << "поиск кол-ва подстроки перебором: \n" << findSubstringsAmount(string, substring);
                break;

        }
    }
    return 0;
}
