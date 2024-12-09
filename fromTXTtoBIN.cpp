#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "bank.h"


Bank Parse(std::stringstream& now) {
    std::string name;
    now>>name;
    std::vector<Ссуда> Ссуды;
    int year, ssuda;
    while (now>>year>>ssuda) {
        Ссуда ssudaa(year, ssuda);
        Ссуды.push_back(ssudaa);
    }
    Bank current_bank(name, Ссуды);
    std::cout<<"[SSParse]>"<<current_bank.GetName()<<std::endl;
    for (auto a = current_bank.GetSsuds().begin(); a!=current_bank.GetSsuds().end();++a) {
        std::cout<<"[SSParse]>"<<(*a).Год<<" "<<(*a).Ссуда_<<std::endl;
    }
    return current_bank;
}


// int main() {
//     ASS *Obj = new ASS();
//     auto *Банки = &(Obj->Банки);

//     for (Итератор старт("first.txt"), конец; старт != конец; ++старт) {
//         Банки->push_back(Bank(Parse(*старт)));
//     }

//     for (auto st = Банки->begin();st!=Банки->end();++st ) {
//         std::cout<<(*st).GetName()<<"----------------"<<std::endl;
//         for (auto elem = (*st).GetSsuds().begin(); elem!=(*st).GetSsuds().end(); ++elem) {
//             std::cout<<"Год: "<<(*elem).Год<<" | Ссуда: "<<(*elem).Ссуда_<<std::endl;
//         }
//         std::cout<<std::endl;
//     }

//     Obj->save("goal.biba");

//     return 0;
// }
