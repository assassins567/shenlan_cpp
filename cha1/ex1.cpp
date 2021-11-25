#include<iostream>
#include<cstdlib>
#include<vector>
#include<chrono>

using namespace std;
using namespace chrono;
//void question() {};

void question()
{
    srand((unsigned)time(NULL));
    cout << "How many questions do you want?" <<endl;
    int q_count;
    while ( !(cin >> q_count) )
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"What you input is illegal, please input again"<<endl;
    }
    
    cout << "Are you willing to do Mult and Sub?[1 for yes, 0 for no]" <<endl;
    int cal;
    //cin >> cal;
    while ( !(cin >> cal) || cal != 0 && cal !=1)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"What you input is illegal, please input again"<<endl;
    }
    int caseCal;
    if(cal == 1) caseCal = 4;
    else caseCal = 2;
    cout << "You will get 10 points with a correct answer" << endl;
    cout << "Ps: You only need to give the int part by dividing." <<endl;
    int score = 0;
    int correct_Ans = 0;
    int fault_Ans = 0;
    vector<int> ans_arr ;
    vector<double> timer;

    for (int i = 0; i < q_count; i++)
    {
        /* code */
        auto start = system_clock::now();
         int f =abs(rand()%100);
         int s = abs(rand()%100);
         int caseM = abs(rand()%caseCal);
         int result = 0;
        cout << "You have still " << q_count - i << " questions" <<endl;
        cout << "The " << i << "."<<" question: " << endl;
        switch (caseM)
        {
        case  0:
            result =f + s;
            cout << f << "+" << s << "=" << endl; 
            break;
        case 1:
            result = f - s;
            cout << f << "-" << s << "=" << endl; 
            break;
        case 2:
            result = f * s;
            cout << f << "*" << s << "=" << endl; 
            break;
        case 3:
            result =(int) f / s;
            cout << f << "/" << s << "=" << endl; 
            break;
        default:
            break;
        }
        cout << "Please give your result: " << endl;
        int input;
        while ( !(cin >> input) )
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"What you input is illegal, please input again"<<endl;
        }
        if (input == result)
        {
            cout << "Your answer is correct!"<<endl;
            correct_Ans ++;
            score += 10;
            cout << "Your present record is " << score  << endl;
        }
        else
        {
            fault_Ans++;
            ans_arr.push_back(result);
            cout << "Your answer is  fault! " << endl;
            //cout << "The correct result is " << result << endl;
            cout << "Your present record is " << score<< endl;
        }
        cout << "\n"  <<endl;
        auto end = system_clock::now();
        auto duration = duration_cast<seconds>(end-start);
        //int du =  (int) duration;
        timer.push_back(duration.count());
    }
    cout << correct_Ans << " answers are correct" << endl;
    cout << fault_Ans << " answers are fault" << endl;
    double sum_time = 0;
    for (size_t j = 0; j < q_count; j++)
    {
        /* code */
        if(ans_arr[j] !=0) 
        {
            cout << "The result of " << j <<" "<< "question is fault and the correct answer is " << ans_arr[j] << endl;
        }
        sum_time += timer[j];
    }
    double mean_time = sum_time/q_count;
    
    cout << "Your final record is " << score  << endl; 
    cout << "Your average answer time is " << mean_time << 's' << endl; 
}



int main(int argc, char **argv)
{
    question();
    return 0;
}