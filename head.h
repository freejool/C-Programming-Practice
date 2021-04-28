#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by sxing on 2021/4/21.
//

#ifndef INC_6__HEAD_H
#define INC_6__HEAD_H

#include "_def_.h"

//W -- Learning rate of Imp to Out
//V -- Learning rate between In to Imp
double data_in[TrainData][In];
double data_out[TrainData][Out];
double test_data_in[TestData][In];
double test_data_out[TestData][Out];
double pre[TestData][Out];              // Actual output of TestData
double u[Imp][In];                      // Learning rate between In to Imp
double v[Imp2][Imp];                    // Learning rate between Imp to Imp2
double w[Out][Imp];                     // Learning rate between Imp2 to Out
double y[Imp];                          // output of Imp
double z[Imp2];                         // output of Imp2
double max_in[In], min_in[In];          // maxi&mini mum of In
double max_out[In], min_out[In];        // maxi&mini mum of Out
double out_put_data[Out];               // Output of network
double u_cor[Imp][In];
double v_cor[Imp2][Imp];
double w_cor[Out][Imp2];                // correction of w and u and v
double mse;                             // Mean Square Error
double rmse;                            // Root mean square error
double tmp1;
double tmp2;


void read_data(char in[], char out[]) {
    FILE *fp1, *fp2;
    char ch;
    if ((fp1 = fopen(in, "rb")) == NULL) {
        printf("Failed to read %s\n", in);
        exit(0);
    }

    for (int i = 0; i < TrainData; ++i) {
        for (int j = 0; j < In; ++j) {
            if (j != 0) {
                fscanf(fp1, "%c", &ch);
            }
            fscanf(fp1, "%lf", &data_in[i][j]);
        }
    }
    fclose(fp1);
    if ((fp2 = fopen(out, "rb")) == NULL) {
        printf("Failed to read %s\n", out);
        exit(0);
    }
    for (int i = 0; i < TrainData; ++i) {
        for (int j = 0; j < Out; ++j) {
            fscanf(fp2, "%lf", &data_out[i][j]);
        }
    }
    fclose(fp2);
}

void init_BP_network() {
    srand((int) time(0));

    for (int i = 0; i < In; ++i) {
        min_in[i] = max_in[i] = data_in[0][i];
        for (int j = 0; j < TrainData; ++j) {
            max_in[i] = max_in[i] > data_in[j][i] ? max_in[i] : data_in[j][i];
            min_in[i] = min_in[i] < data_in[j][i] ? min_in[i] : data_in[j][i];
        }
    }

    for (int i = 0; i < Out; ++i) {
        min_out[i] = max_out[i] = data_out[0][i];
        for (int j = 0; j < TrainData; ++j) {
            max_out[i] = max_out[i] > data_out[j][i] ? max_out[i] : data_out[j][i];
            min_out[i] = min_out[i] < data_out[j][i] ? min_out[i] : data_out[j][i];
        }
    } // detect maximum and minimum of input and output data

    for (int i = 0; i < In; ++i) {
        for (int j = 0; j < TrainData; ++j) {
            data_in[j][i] = (data_in[j][i] - min_in[i]) / (max_in[i] - min_in[i]);
        }
    } // Normalization for data_in

    for (int i = 0; i < Out; ++i) {
        for (int j = 0; j < TrainData; ++j) {
            data_out[j][i] = (data_out[j][i] - min_out[i]) / (max_out[i] - min_out[i]);
        }
    } // Normalization for data_out

    for (int i = 0; i < Imp; ++i) {
        for (int j = 0; j < In; ++j) {
            u[i][j] = rand() * 2.0 / RAND_MAX - 1; // within [-1,1]
            u_cor[i][j] = 0;
        }
    } // Randomize u

    for (int i = 0; i < Imp2; ++i) {
        for (int j = 0; j < Imp; ++j) {
            v[i][j] = rand() * 2.0 / RAND_MAX - 1;
            v_cor[j][i] = 0;
        }
    } // Randomize v

    for (int i = 0; i < Out; ++i) {
        for (int j = 0; j < Imp2; ++j) {
            w[i][j] = rand() * 2.0 / RAND_MAX - 1;
            w_cor[j][i] = 0;
        }
    } // Randomize w
}

void compute_forward(int var);  // Forward propagation function
void feed_back(int var);          // Backward correction function

void train_network() {
    int count = 1; // num of training times
    do {
        mse = 0;
        for (int i = 0; i < TrainData; ++i) {
            compute_forward(i);     // Go forward
            feed_back(i);           // Go backward
            for (int j = 0; j < Out; ++j) {
                tmp1 = out_put_data[j] * (max_out[j] - min_out[j]) + min_out[j];
                tmp2 = data_out[i][j] * (max_out[j] - min_out[j]) + min_out[j];
                mse += (tmp1 - tmp2) * (tmp1 - tmp2);
            }
        }
        mse = mse / (TrainData * Out);

        if (count % 1000 == 0) {
            printf("%-6d  %lf\n", count, mse);
        }
        count++;
    } while (mse >= REQUIRED_MSE);
    printf("Done training!\n");
}

void compute_forward(int var) {
    double sum;
    for (int i = 0; i < Imp; ++i) {
        sum = 0;
        for (int j = 0; j < In; ++j) {
            sum += u[i][j] * data_in[var][j];
        }
        y[i] = 1 / (1 + exp(-1 * sum));
    }
    for (int i = 0; i < Imp2; ++i) {
        sum = 0;
        for (int j = 0; j < Imp; ++j) {
            sum += v[i][j] * y[j];
        }
        z[i] = 1 / (1 + exp(-1 * sum));
    }
    for (int i = 0; i < Out; ++i) {
        sum = 0;
        for (int j = 0; j < Imp; ++j) {
            sum += w[i][j] * z[j];
        }
        out_put_data[i] = 1 / (1 + exp(-1 * sum));
    }
}

void feed_back(int var) {
//    double t;
//    for (int i = 0; i < Imp2; ++i) {
//        t = 0;
//        for (int j = 0; j < Out; ++j) {
//            w_cor[j][i] = WAlta * (data_out[var][j] - out_put_data[j]) * out_put_data[j] * (1 - out_put_data[j]) * z[i];
//            w[j][i] += w_cor[j][i];
//            t += (data_out[var][j] - out_put_data[j]) * out_put_data[j] * (1 - out_put_data[j]) * w[j][i];
//        }
//    }
//    for (int j = 0; j < Out; ++j) {
//        w_cor[j][i] = VAlta * t * y[i] * (1 - y[i]) * data_in[var][j];
//        u[i][j] += v_cor[i][j];
//    }
    double delta_Out[Out];
    double delta_Imp[Imp];
    double delta_Imp2[Imp2];
    memset(delta_Out, 0, sizeof(double) * Out);
    memset(delta_Imp, 0, sizeof(double) * Imp);
    memset(delta_Imp2, 0, sizeof(double) * Imp2);

    for (int i = 0; i < Out; ++i) {
        delta_Out[i] += data_out[var][i] - out_put_data[i];
    }
    for (int i = 0; i < Imp2; ++i) {
        for (int j = 0; j < Out; ++j) {
            delta_Imp2[i] += w[j][i] * delta_Out[j];
        }
    }
    for (int i = 0; i < Imp; ++i) {
        for (int j = 0; j < Imp2; ++j) {
            delta_Imp[i] += v[j][i] * delta_Imp2[j];
        }
    }
    /* compute delta of neurons */
    for (int i = 0; i < Imp; ++i) {
        for (int j = 0; j < In; ++j) {
            u_cor[i][j] = UAlta * delta_Imp[i] * data_in[var][j] * y[i] * (1 - y[i]);
            u[i][j] += u_cor[i][j];
        }
    }
    for (int i = 0; i < Imp2; ++i) {
        for (int j = 0; j < Imp; ++j) {
            v_cor[i][j] = VAlta * delta_Imp2[i] * y[j] * z[i] * (1 - z[i]);
            v[i][j] += v_cor[i][j];
        }
    }
    for (int i = 0; i < Out; ++i) {
        for (int j = 0; j < Imp2; ++j) {
            w_cor[i][j] = WAlta * delta_Out[i] * z[j] * out_put_data[i] * (1 - out_put_data[i]);
            w[i][j] += w_cor[i][j];
        }
    }

}

void test_network(char test_file_name[]) {
    FILE *fp;
    char ch;
    if ((fp = fopen(test_file_name, "rb")) == NULL) {
        printf("Failed to read %s\n", test_file_name);
        exit(0);
    }
    for (int i = 0; i < TestData; ++i) {
        for (int j = 0; j < In + Out; ++j) {
            if (j != 0) {
                fscanf(fp, "%c", &ch);
            }
            if (j < In) {
                fscanf(fp, "%lf", &test_data_in[i][j]);
            } else {
                fscanf(fp, "%lf", &test_data_out[i][j - In]);
            }
        }
    }
    fclose(fp);
    for (int i = 0; i < In; ++i) {
        for (int j = 0; j < TestData; ++j) {
            test_data_in[j][i] = (test_data_in[j][i] - min_in[i]) / (max_in[i] - min_in[i]);
        }
    }
    for (int var = 0; var < TestData; ++var) {
//        for (int i = 0; i < Imp; ++i) {
//            sum = 0;
//            for (int j = 0; j < In; ++j) {
//                sum += u[i][j] * test_data_in[var][j];
//            }
//            y[i] = 1 / (1 + exp(-1 * sum));
//        }
//        sum = 0;
//        for (int j = 0; j < Imp; ++j) {
//            sum += w[0][j] * y[j];
//        }
        for (int i = 0; i < Imp; ++i) {
            y[i] = 0;
            for (int j = 0; j < In; ++j) {
                y[i] += test_data_in[var][j] * u[i][j];
            }
            y[i] = 1 / (1 + exp(-1 * y[i]));
        }
        for (int i = 0; i < Imp2; ++i) {
            z[i] = 0;
            for (int j = 0; j < Imp; ++j) {
                z[i] += y[j] * v[i][j];
            }
            z[i] = 1 / (1 + exp(-1 * z[i]));
        }
        for (int i = 0; i < Out; ++i) {
            pre[var][i] = 0;
            for (int j = 0; j < Imp2; ++j) {
                pre[var][i] += z[j] * w[i][j];
            }
            pre[var][i] = 1 / (1 + exp(-1 * pre[var][i])) * (max_out[i] - min_out[i]) + min_out[i];
            printf("No. %-3d Predicted values: %-4.2lf Actual value: %-4.2lf\n", var + 1, pre[var][i],
                   test_data_out[var][i]);
        }
    }
    rmse = 0.0;
    for (int var = 0; var < TestData; ++var) {
        rmse += (pre[var][0] - test_data_out[var][0]) * (pre[var][0] - test_data_out[var][0]);
    }
    rmse = sqrt(rmse / TestData);
    printf("rmse: %.4lf\n", rmse);
} // test the network using data in test.txt


#endif //INC_6__HEAD_H

#pragma clang diagnostic pop