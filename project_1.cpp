#include <iostream>
#include <cmath>

int main ();
int main() {
    
    double Fmax, Mmax, P1max, P2max, P3max, P4max, P5max;
    double F, M, P1, P2, P3, P4, P5;
do {
        std::cout << "Enter the maximum grade:";
        std::cin >> Fmax;
        } while (Fmax <= 0 or Fmax != std::round(Fmax));
 do {
        std::cout<< "Enter the achieved grades for the final exam:";
        std::cin >> F;
    } while (F < 0 || F > Fmax);
  
  do {
        std::cout << "Enter the maximum grade:";
        std::cin >> Mmax;
        } while (Mmax <= 0 or Mmax != std::round(Mmax));
 do {
        std::cout<< "Enter the achieved grades for the final exam:";
        std::cin >> M;
    } while (M < 0 || M > Mmax);

do {
        std::cout << "Enter the maximum grade:";
        std::cin >> P1max;
        } while (P1max <= 0 or P1max != std::round(P1max));
 do {
        std::cout<< "Enter the achieved grades for the final exam:";
        std::cin >> P1;
    } while (P1 < 0 || P1 > P1max);

do {
        std::cout << "Enter the maximum grade:";
        std::cin >> P2max;
        } while (P2max <= 0 or P2max != std::round(P2max));
 do {
        std::cout<< "Enter the achieved grades for the final exam:";
        std::cin >> P2;
    } while (P2 < 0 || P2 > P2max);

do {
        std::cout << "Enter the maximum grade:";
        std::cin >> P3max;
        } while (P3max <= 0 or P3max != std::round(P3max));
 do {
        std::cout<< "Enter the achieved grades for the final exam:";
        std::cin >> P3;
    } while (P3 < 0 || P3 > P3max);

    do {
        std::cout << "Enter the maximum grade:";
        std::cin >> P4max;
        } while (P4max <= 0 or P4max != std::round(P4max));
 do {
        std::cout<< "Enter the achieved grades for the final exam:";
        std::cin >> P4;
    } while (P4 < 0 || P4 > P4max);

do {
        std::cout << "Enter the maximum grade:";
        std::cin >> P5max;
        } while (P5max <= 0 or P5max != std::round(P5max));
 do {
        std::cout<< "Enter the achieved grades for the final exam:";
        std::cin >> P5;
    } while (P5 < 0 || P5 > P5max);

 double F_100{100*F/Fmax};
 double M_100{100*M/Mmax};
 double P1_100{100*P1/P1max};
 double P2_100{100*P2/P2max};
 double P3_100{100*P3/P3max};
 double P4_100{100*P4/P4max};
 double P5_100{100*P5/P5max};

    if (M_100 < F_100) M_100 = F_100;
    if (P1_100 < F_100) P1_100 = F_100;
    if (P2_100 < F_100) P2_100 = F_100;
    if (P3_100 < F_100) P3_100 = F_100;
    if (P4_100 < F_100) P4_100 = F_100;
    if (P5_100 < F_100) P5_100 = F_100;

double E_100;
E_100 = (3.0/4.0*F_100) + (1.0/4.0*M_100);

double P_100;
P_100 = (P1_100 + P2_100 + P3_100 + P4_100 + P5_100)/(5.0);

double final_grade = 0;
if (E_100 <= 40) {
    final_grade = E_100;
} else if (E_100 >= 60) {
    final_grade = ((2.0/3.0)*E_100) + ((1.0/3.0)*P_100);
} else  {
    final_grade = (P_100*(1.0/3.0)*((E_100-40.0)/20.0)) + (E_100*(1-((1.0/3.0)*(E_100-40.0)/20.0)));
}   

final_grade = std::round(final_grade);
std::cout << "The final grade is:" << std::round( final_grade + 1e-12 ) << std::endl;

    return 0;
}
  





