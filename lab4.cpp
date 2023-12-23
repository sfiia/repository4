#include <iostream>
#include <fstream>

using namespace std;
int line_down_times;
int const wordsLen = 10, startWords = 50;
char symbols[] = {'!', ',', ' ',
                  '?', ':', ';',
                  '-', };


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
    fin.close();
}


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


int amountOfSubstr(char string[], char substring[]) {
    bool flag;
    int counter = 0;
    int strLen = strlen(string), substrLen = strlen(substring);
    for ( int i = 0; i <= strLen - substrLen; i++ ){
        flag = true;
        for ( int j = 0; j < substrLen; j++ ){
            if (substring[j] != string[i + j]){
                flag = false;
                break;
            }
        }
        if (flag){
            counter++;
        }
    }
    return counter;
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


void verticalCout(char string[]){
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
                }
                else{
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
                verticalCout(string);
                cout << string;
                break;

            case 5:

