#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double t, double* y, int i);

int main(void) {
    FILE *file = fopen("/Users/file.txt", "w");
    int N = 10000;
    double t_l = 0, t_r = 30 * M_PI;
    double t_old = 0, t_new = 0;
    double y_0 = 1, x_0 = 0., y0_real, y1_real, h = 0, h_last = 0, R0,R1,R;
    double *y_old = (double* ) malloc((2) * sizeof(double));
    double *y_new = (double* ) malloc((2) * sizeof(double));
    y0_real = sin(t_r);
    y1_real = cos(t_r);
    y_old[0] = x_0;
    y_old[1] = y_0;
    t_old = t_l;
    fprintf(file, "%.10f %.10f \n", y_old[0], y_old[1]);
    h = (t_r - t_l)/N;
    printf("h = %.10f\n", h);

    for(int i = 1; i < N; i++){
        y_new[0] = y_old[0] + h * f(t_old, y_old, 0);
        y_new[1] = y_old[1] + h * f(t_old, y_old, 1);
        t_new = t_old + h;
        fprintf(file, "%.10f %.10f \n", y_new[0], y_new[1]);
        y_old[0] = y_new[0];
        y_old[1] = y_new[1];
        t_old = t_new;
    }
    h_last = t_r - t_old;
    t_new = t_r;
    y_new[0] = y_old[0] + h_last * f(t_old, y_old, 0);
    y_new[1] = y_old[1] + h_last * f(t_old, y_old, 1);
    //printf("h_last = %.10f\n", h_last);
    R0 = fabs(y_new[0] - y0_real); R1 = fabs(y_new[1] - y1_real);
    R = sqrt(R0*R0 + R1*R1);
    printf("R0 = %.20f R1 = %.20f \nR = %.20f", R0, R1,R);
    fprintf(file, "%.10f %.10f \n", y_new[0], y_new[1]);

    free(y_new);
    free(y_old);
    fclose(file);

    return 0;
}

double f(double t, double* y, int i) {
    if(i == 0) {
        return y[1];
    }
    if(i == 1) {
        return - y[0];
    }

}

//set grid ytics; set grid xtics; plot '/Users/kirill/Desktop/file_euler_vector.txt' w l
