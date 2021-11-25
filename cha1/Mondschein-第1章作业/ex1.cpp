#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;
//void question() {};

void question()
{
    srand((unsigned)time(NULL));
    cout << "How many questions do you want?" <<endl;
    int q_count;
    cin >> q_count;
    cout << "Are you willing to do Mult and Sub?[1 for yes, 0 for no]" <<endl;
    int cal;
    cin >> cal;
    int caseCal;
    if(cal == 1) caseCal = 4;
    else caseCal = 2;
    cout << "You will get 10 points with a correct answer" << endl;
    cout << "Ps: You only need to give the int part by dividing." <<endl;
    int score = 0;
    int correct_Ans = 0;
    int fault_Ans = 0;
    int ans_arr[500] = {0};

    for (int i = 0; i < q_count; i++)
    {
        /* code */
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
        cin >> input;
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
            ans_arr[i] = result;
            cout << "Your answer is  fault! " << endl;
            //cout << "The correct result is " << result << endl;
            cout << "Your present record is " << score<< endl;
        }
        cout << "\n"  <<endl;

    }
    cout << correct_Ans << " answers are correct" << endl;
    cout << fault_Ans << " answers are fault" << endl;
    for (size_t j = 0; j < q_count; j++)
    {
        /* code */
        if(ans_arr[j] !=0) 
        {
            cout << "The result of " << j <<" "<< "question is fault and the correct answer is " << ans_arr[j] << endl;
        }
    }
    
    cout << "Your final record is " << score  << endl; 
}



int main()
{
    question();
    return 0;
}