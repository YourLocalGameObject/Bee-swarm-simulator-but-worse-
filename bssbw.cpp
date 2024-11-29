#include <iostream>
#include <string>
using namespace std;

int main(){
    int honey_total = 0;
    int honey_collected = 0;
    int fruit_total = 0;
    int fruit_collected = 0;
    int unique_honey_total = 0;
    int unique_honey_collected = 0;
    int honey_per_click = 1;
    int unique_honey_per_click = 0;
    int click_count = 0;
    int times_wrote_bad = 0;
    string command;

    int normal_egg_price = 5;

    int unique_egg_honey = 30;
    int unique_egg_fruit = 1;

    int lucky_egg_honey = 120;
    int lucky_egg_unique_honey = 40;
    int lucky_egg_fruit = 2;
    int clicks_till_fruit = 20;

    int price_egg_honey = 1500;
    int price_egg_unique_honey = 350;
    int price_egg_fruit = 4;

    int better_tool_honey = 1000;
    int better_tool_unique_honey = 300;
    int better_tool_fruit = 5;

    int win_badge_honey = 2500;
    int win_badge_unique_honey = 500;
    int win_badge_fruit = 8;

    int normal_bee_count = 0;
    int unique_bee_count = 0;
    int lucky_bee_count = 0;
    int price_bee_count = 0;
    bool better_tool_purchased = false;

    cout << "\nWelcome to Bee Swarm Simulator But Worse! (bssbw for short)" << endl;
    cout << "\nWrite \"click\" to get honey!" << endl;
    cout << "Write \"stats\" to look at your statistics!" << endl;
    cout << "Write \"bee shop\" to open up the bee shop!" << endl;
    cout << "Write \"tool shop\" to open up the tool shop!" << endl;

    bool loopie = true;
    while(loopie){
        getline(cin, command);
        
        if(command == "click"){
            click_count++;
            honey_total += honey_per_click;
            honey_collected += honey_per_click;

            cout << "\nYou now have " << honey_total << " honey!" << endl;

            if(unique_honey_per_click > 0){
                unique_honey_total += unique_honey_per_click;
                unique_honey_collected += unique_honey_per_click;
                cout << "You now have " << unique_honey_total << " unique honey!" << endl;
            }

            if(click_count % clicks_till_fruit == 0){
                fruit_total++;
                fruit_collected++;
                cout << "You have found a fruit! (you have " << fruit_total << " fruit)" << endl;
            }
        }
        else if(command == "bee shop"){
            bool loopie_bee_shop = true;
            while(loopie_bee_shop){
                cout << "\n\nHi! Welcome to the bee shop! Here, you can buy bee eggs to hatch into bees!\n" << endl;
                cout << "Write the name of the egg to buy it!" << endl;
                cout << "Write \"exit\" to exit the bee shop!\n" << endl;

                cout << "\nYour total honey is " << honey_total << " honey" << endl;
                cout << "Your total unique honey is " << unique_honey_total << " unique honey" << endl;
                cout << "Your total fruit is " << fruit_total << " fruit" << endl;
                cout << "\nnormal egg: " << normal_egg_price << " honey" << endl;
                cout << "unique egg: " << unique_egg_honey << " honey, " << unique_egg_fruit << " fruit" << endl;
                cout << "lucky egg: " << lucky_egg_honey << " honey, " << lucky_egg_unique_honey << " unique honey, " << lucky_egg_fruit << " fruit\n";
                cout << "price egg: " << price_egg_honey << " honey, " << price_egg_unique_honey << " unique honey, " << price_egg_fruit << " fruit\n";

                getline(cin, command);

                if(command == "normal egg"){
                    if(honey_total >= normal_egg_price){
                        honey_total -= normal_egg_price;
                        honey_per_click++;
                        normal_egg_price *= 2;
                        normal_bee_count++;

                        cout << "\n\nYou bought a normal egg!" << endl;
                        cout << "And you got a normal bee!" << endl;
                        cout << "\nWrite \"info normal bee\" to get the info about it!" << endl;
                        cout << "Write \"exit\" to go back to the bee shop!" << endl;
                        cout << "Write \"exit bee shop\" to exit the bee shop!" << endl;

                        while(true){
                            getline(cin, command);

                            if(command == "info normal bee"){
                                cout << "\n\nNormal bee, is a normal bee!\n" << endl;
                                cout << "You also make 1 more honey with every click you make!" << endl;
                                cout << "\nWrite \"exit\" to go back to the shop" << endl;
                                cout << "Write \"exit bee shop\" to exit the bee shop" << endl;
                            }
                            else if(command == "exit"){
                                cout << "\n\nGoing back to the bee shop..." << endl;
                                break;
                            }
                            else if(command == "exit bee shop"){
                                cout << "\n\nExiting bee shop..." << endl;
                                loopie_bee_shop = false;
                                break;
                            }
                            else{
                                times_wrote_bad++;
                                cout << "\nUnknown command! Please write one of the following:" << endl;
                                cout << "   Write \"info normal bee\" to get the info about the normal bee!" << endl;
                                cout << "   Write \"exit\" to go back to the shop!" << endl;
                                cout << "   Write \"exit bee shop\" to leave the bee shop!" << endl;
                            }
                        }
                    }
                    else{
                        cout << "\nNot enough honey to buy a normal egg!" << endl;
                    }
                }
                else if(command == "unique egg"){
                    if(honey_total >= unique_egg_honey && fruit_total >= unique_egg_fruit){
                        honey_total -= unique_egg_honey;
                        fruit_total -= unique_egg_fruit;
                        honey_per_click += 2;
                        unique_honey_per_click += 1;
                        unique_egg_honey *= 2;
                        unique_bee_count++;

                        cout << "\n\nYou bought a unique egg!" << endl;
                        cout << "And you got a unique bee!" << endl;
                        cout << "\nWrite \"info unique bee\" to get the info about it!" << endl;
                        cout << "Write \"exit\" to go back to the bee shop!" << endl;
                        cout << "Write \"exit bee shop\" to exit the bee shop!" << endl;

                        while(true){
                            getline(cin, command);

                            if(command == "info unique bee"){
                                cout << "\n\nUnique bee is so unique that it is only called a bee because it has the shape of one" << endl;
                                cout << "With it you can collect 2 more honey!" << endl;
                                cout << "With it you can also collect 1 unique honey! A type of honey that only unique bees can collect!" << endl;
                                cout << "\nWrite \"exit\" to go back to the shop" << endl;
                                cout << "Write \"exit bee shop\" to exit the bee shop" << endl;
                            }
                            else if(command == "exit"){
                                cout << "\n\nGoing back to the bee shop..." << endl;
                                break;
                            }
                            else if(command == "exit bee shop"){
                                cout << "\n\nExiting bee shop..." << endl;
                                loopie_bee_shop = false;
                                break;
                            }
                            else{
                                times_wrote_bad++;
                                cout << "\nUnknown command! Please write one of the following:" << endl;
                                cout << "   Write \"info unique bee\" to get the info about unique bee!" << endl;
                                cout << "   Write \"exit\" to go back to the shop!" << endl;
                                cout << "   Write \"exit bee shop\" to leave the bee shop!" << endl;
                            }
                        }
                    }
                    else{
                        cout << "\nNot enough to buy a unique egg!" << endl;
                    }
                }
                else if(command == "lucky egg"){
                    if(honey_total >= lucky_egg_honey && unique_honey_total >= lucky_egg_unique_honey && fruit_total >= lucky_egg_fruit){
                        honey_total -= lucky_egg_honey;
                        unique_honey_total -= lucky_egg_unique_honey;
                        fruit_total -= lucky_egg_fruit;
                        honey_per_click += 2;
                        lucky_egg_honey *= 2;
                        lucky_egg_unique_honey *= 2;
                        lucky_bee_count++;

                        if(clicks_till_fruit > 2){
                            clicks_till_fruit -= 2;
                        }

                        cout << "\n\nYou bought a lucky egg!" << endl;
                        cout << "And you got a lucky bee!" << endl;
                        cout << "\nWrite \"info lucky bee\" to get the info about it!" << endl;
                        cout << "Write \"exit\" to go back to the bee shop!" << endl;
                        cout << "Write \"exit bee shop\" to exit the bee shop!" << endl;

                        while(true){
                            getline(cin, command);

                            if(command == "info lucky bee"){
                                cout << "\n\nLucky bee is so lucky that gamblers started owning them as pets for good luck!" << endl;
                                cout << "With it you can collect 2 more honey!" << endl;
                                cout << "With it you can also collect fruit x1.1 quickly!" << endl;
                                cout << "\nWrite \"exit\" to go back to the shop" << endl;
                                cout << "Write \"exit bee shop\" to exit the bee shop" << endl;
                            }
                            else if(command == "exit"){
                                cout << "\n\nGoing back to the bee shop..." << endl;
                                break;
                            }
                            else if(command == "exit bee shop"){
                                cout << "\n\nExiting bee shop..." << endl;
                                loopie_bee_shop = false;
                                break;
                            }
                            else{
                                times_wrote_bad++;
                                cout << "\nUnknown command! Please write one of the following:" << endl;
                                cout << "   Write \"info lucky bee\" to get the info about lucky bee!" << endl;
                                cout << "   Write \"exit\" to go back to the shop!" << endl;
                                cout << "   Write \"exit bee shop\" to leave the bee shop!" << endl;
                            }
                        }
                    }
                    else{
                        cout << "\nNot enough to buy a lucky egg!" << endl;
                    }
                }
                else if(command == "price egg"){
                    if(honey_total >= price_egg_honey && unique_honey_total >= price_egg_unique_honey && fruit_total >= price_egg_fruit){
                        honey_total -= price_egg_honey;
                        unique_honey_total -= price_egg_unique_honey;
                        fruit_total -= price_egg_fruit;
                        honey_per_click += 4;
                        normal_egg_price /= 2;
                        unique_egg_honey /= 2;
                        unique_egg_fruit /= 2;
                        lucky_egg_honey /= 2;
                        lucky_egg_unique_honey /= 2;
                        lucky_egg_fruit /= 2;
                        price_egg_honey *= 1.5;
                        price_egg_unique_honey *= 1.5;
                        price_egg_fruit += 2;
                        price_bee_count++;

                        cout << "\n\nYou bought a price egg!" << endl;
                        cout << "And you got a price bee!" << endl;
                        cout << "\nWrite \"info price bee\" to get the info about it!" << endl;
                        cout << "Write \"exit\" to go back to the bee shop!" << endl;
                        cout << "Write \"exit bee shop\" to exit the bee shop!" << endl;

                        while(true){
                            getline(cin, command);

                            if(command == "info price bee"){
                                cout << "\n\nPrice bee looks for every deal she can find!" << endl;
                                cout << "With her you can collect 4 more honey!" << endl;
                                cout << "Upon buying her, she cuts the prices of all eggs in half! (excluding price eggs)" << endl;
                                cout << "\nWrite \"exit\" to go back to the shop" << endl;
                                cout << "Write \"exit bee shop\" to exit the bee shop" << endl;
                            }
                            else if(command == "exit"){
                                cout << "\n\nGoing back to the bee shop..." << endl;
                                break;
                            }
                            else if(command == "exit bee shop"){
                                cout << "\n\nExiting bee shop..." << endl;
                                loopie_bee_shop = false;
                                break;
                            }
                            else{
                                times_wrote_bad++;
                                cout << "\nUnknown command! Please write one of the following:" << endl;
                                cout << "   Write \"info price bee\" to get the info about price bee!" << endl;
                                cout << "   Write \"exit\" to go back to the shop!" << endl;
                                cout << "   Write \"exit bee shop\" to leave the bee shop!" << endl;
                            }
                        }
                    }
                    else{
                        cout << "\nNot enough to buy a price egg!" << endl;
                    }
                }
                else if(command == "exit"){
                    loopie_bee_shop = false;
                    cout << "\n\nExiting bee shop...\n" << endl;
                }
                else{
                    times_wrote_bad++;
                    cout << "\nUnknown command! Please write one of the following:" << endl;
                    cout << "   Write \"normal egg\" to buy a normal egg!" << endl;
                    cout << "   Write \"unique egg\" to buy a unique egg!" << endl;
                    cout << "   Write \"lucky egg\" to buy a lucky egg!" << endl;
                    cout << "   Write \"price egg\" to buy a price egg!" << endl;
                    cout << "   Write \"exit\" to exit the bee shop!" << endl;
                }
            }
            cout << "\nWrite \"click\" to get honey, \"bee shop\" to open up the bee shop, \"tool shop\" to open up the tool shop and \"stats\" to look at your stats!\n";
        }
        else if(command == "tool shop"){
            bool loopie_tool_shop = true;
            while(loopie_tool_shop){
                cout << "\n\nHi! Welcome to the tool shop! Here, you can buy tools to get more stuff!\n" << endl;
                cout << "Write the name of the tool to buy it!" << endl;
                cout << "Write \"exit\" to exit the tool shop!\n" << endl;

                cout << "\nYour total honey is " << honey_total << " honey" << endl;
                cout << "Your total unique honey is " << unique_honey_total << " unique honey" << endl;
                cout << "Your total fruit is " << fruit_total << " fruit" << endl;

                if(!better_tool_purchased){
                    cout << "\nbetter tool: " << better_tool_honey << " honey, " << better_tool_unique_honey << " unique honey, " << better_tool_fruit << " fruit\n";
                }
                else{
                    cout << "\nbetter tool: purchased" << endl;
                }

                cout << "win badge: " << win_badge_honey << " honey, " << win_badge_unique_honey << " unique honey, " << win_badge_fruit << " fruit\n";
                getline(cin, command);

                if(command == "better tool"){
                    if(better_tool_purchased){
                        cout << "\nYou already have the better tool!" << endl;
                    }
                    else if(honey_total >= better_tool_honey && unique_honey_total >= better_tool_unique_honey && fruit_total >= better_tool_fruit){
                        honey_total -= better_tool_honey;
                        unique_honey_total -= better_tool_unique_honey;
                        fruit_total -= better_tool_fruit;
                        honey_per_click *= 1.5;
                        better_tool_purchased = true;


                        cout << "\n\nYou bought a better tool!" << endl;
                        cout << "\nWrite \"info better tool\" to get the info about it!" << endl;
                        cout << "Write \"exit\" to go back to the tool shop!" << endl;
                        cout << "Write \"exit tool shop\" to exit the bee shop!" << endl;

                        while(true){
                            getline(cin, command);

                            if(command == "info better tool"){
                                cout << "\n\nThe better tool is better than the starter tool. UwU" << endl;
                                cout << "With it you can collect x1.5 more total honey!" << endl;
                                cout << "\nWrite \"exit\" to go back to the shop" << endl;
                                cout << "Write \"exit tool shop\" to exit the tool shop" << endl;
                            }
                            else if(command == "exit"){
                                cout << "\n\nGoing back to the tool shop..." << endl;
                                break;
                            }
                            else if(command == "exit tool shop"){
                                cout << "\n\nExiting tool shop..." << endl;
                                loopie_tool_shop = false;
                                break;
                            }
                            else{
                                times_wrote_bad++;
                                cout << "\nUnknown command! Please write one of the following:" << endl;
                                cout << "   Write \"info better tool\" to get the info about the normal bee!" << endl;
                                cout << "   Write \"exit\" to go back to the shop!" << endl;
                                cout << "   Write \"exit tool shop\" to leave the bee shop!" << endl;
                            }
                        }
                    }
                    else{
                        cout << "\nNot enough to buy better tool!" << endl;
                    }
                }
                else if(command == "win badge"){
                    if(honey_total >= win_badge_honey && unique_honey_total >= win_badge_unique_honey && fruit_total >= win_badge_fruit){
                        honey_total -= win_badge_honey;
                        unique_honey_total -= win_badge_unique_honey;
                        fruit_total -= win_badge_fruit;

                        cout << "\n\nThanks for playing Bee Swarm Simulator But Worse!! :)" << endl;
                        return 0;
                    }
                    else{
                        cout << "\nNot enough to buy a win badge!" << endl;
                    }
                }
                else if(command == "exit"){
                    cout << "\nExiting tool shop..." << endl;
                    loopie_tool_shop = false;
                }
            }
            cout << "\nWrite \"click\" to get honey, \"bee shop\" to open up the bee shop, \"tool shop\" to open up the tool shop and \"stats\" to look at your stats!\n";
        }
        else if(command == "stats"){
            bool loopie_stats = true;
            while(loopie_stats){
                cout << "\n\nYour stats: " << endl;
                cout << "click count: " << click_count << endl;
                cout << "honey per click: " << honey_per_click << endl;
                cout << "unique honey per click: " << unique_honey_per_click << endl;
                cout << "clicks till fruit: " << clicks_till_fruit << endl;
                cout << "\nhoney collected: " << honey_collected << endl;
                cout << "unique honey collected: " << unique_honey_collected << endl;
                cout << "fruit collected: " << fruit_collected << endl;
                cout << "\ncurrent honey: " << honey_total << endl;
                cout << "current unique honey: " << unique_honey_total << endl;
                cout << "current fruit: " << fruit_total << endl;
                cout << "\nnormal bees equiped: " << normal_bee_count << endl;
                cout << "unique bees equiped: " << unique_bee_count << endl;
                cout << "lucky bees equiped: " << lucky_bee_count << endl;
                cout << "price bees equiped: " << price_bee_count << endl;
                if(better_tool_purchased){
                    cout << "\nBetter tool purchased: yes" << endl;
                }
                else{
                    cout << "\nBetter tool purchased: no" << endl;
                }
                cout << "\ntimes you wrote a command incorrectly: " << times_wrote_bad << endl;
                cout << "\nWrite \"exit\" to exit stats" << endl;
                getline(cin, command);

                if(command == "exit"){
                    cout << "Exiting stats..." << endl;
                    loopie_stats = false;
                }
            }
            cout << "\nWrite \"click\" to get honey, \"bee shop\" to open up the bee shop, \"tool shop\" to open up the tool shop and \"stats\" to look at your stats!\n";
        }
        else{
            times_wrote_bad++;
            cout << "\nUnknown command! Please write one of the following:" << endl;
            cout << "   Write \"click\" to get honey!" << endl;
            cout << "   Write \"stats\" to look at your statistics!" << endl;
            cout << "   Write \"bee shop\" to get to the bee shop!" << endl;
            cout << "   Write \"tool shop\" to get to the tool shop!" << endl;
        }
    }
}
