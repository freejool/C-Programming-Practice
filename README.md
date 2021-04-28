# 《第6章 波士顿房价预测项目》实验报告

### 一、实验内容

- 完成书上例题的功能（不能照抄例题代码，自行编写）。

- 增加和减少隐含层神经元的个数，观察和比较达到相同精度的情况下训练次数的变化，以及对测试数据的测试精度。

- 为隐含层添加一层神经元，再做第2项内容。

### 二、实验报告

- 提供运行结果截图，对结果进行分析，给出结论。

- 源代码作为附录。

我的想法： C语言的面向过程特性导致添加、删除神经元和隐含层和修改激活函数时极为繁杂，后续考虑使用C++重构。

### 分析：

- 将方差要求设为0.5，经过6000次训练后达到要求，查看result.txt发现输出符合状况较好

### 运行结果

```
sxing@SXY:~$ ./a.out ./in.txt ./out.txt ./test.txt ./result.txt
1000    2.065193
2000    1.095378
3000    0.784728
4000    0.621615
5000    0.507636
Done training!
rmse: 3.1082

No. 1   Predicted values: 28.54  Actual value: 21.20
No. 2   Predicted values: 9.79   Actual value: 10.20
No. 3   Predicted values: 22.38  Actual value: 19.30
No. 4   Predicted values: 20.12  Actual value: 19.40
No. 5   Predicted values: 20.02  Actual value: 19.50
No. 6   Predicted values: 15.80  Actual value: 19.10
No. 7   Predicted values: 24.99  Actual value: 24.80
No. 8   Predicted values: 29.76  Actual value: 28.50
No. 9   Predicted values: 32.25  Actual value: 37.30
No. 10  Predicted values: 12.75  Actual value: 15.20
No. 11  Predicted values: 31.18  Actual value: 33.00
No. 12  Predicted values: 30.12  Actual value: 23.70
No. 13  Predicted values: 37.10  Actual value: 33.80
No. 14  Predicted values: 33.81  Actual value: 31.50
No. 15  Predicted values: 35.75  Actual value: 32.50
No. 16  Predicted values: 22.41  Actual value: 20.60
No. 17  Predicted values: 18.75  Actual value: 20.50
No. 18  Predicted values: 18.77  Actual value: 16.40
No. 19  Predicted values: 27.40  Actual value: 29.00
No. 20  Predicted values: 16.15  Actual value: 17.80
No. 21  Predicted values: 16.40  Actual value: 14.30
No. 22  Predicted values: 18.91  Actual value: 21.60
No. 23  Predicted values: 20.04  Actual value: 15.60
No. 24  Predicted values: 18.60  Actual value: 19.10
No. 25  Predicted values: 23.19  Actual value: 22.50
No. 26  Predicted values: 16.58  Actual value: 17.20
No. 27  Predicted values: 49.07  Actual value: 42.80
No. 28  Predicted values: 48.79  Actual value: 43.80
No. 29  Predicted values: 15.05  Actual value: 27.10
No. 30  Predicted values: 46.47  Actual value: 50.00
No. 31  Predicted values: 36.92  Actual value: 35.40
No. 32  Predicted values: 18.16  Actual value: 14.90
No. 33  Predicted values: 15.42  Actual value: 18.30
No. 34  Predicted values: 27.35  Actual value: 30.50
No. 35  Predicted values: 49.22  Actual value: 50.00
No. 36  Predicted values: 7.51   Actual value: 5.00
No. 37  Predicted values: 21.87  Actual value: 19.40
No. 38  Predicted values: 7.28   Actual value: 8.40
No. 39  Predicted values: 7.78   Actual value: 5.00
No. 40  Predicted values: 16.02  Actual value: 21.40
No. 41  Predicted values: 22.01  Actual value: 20.60
No. 42  Predicted values: 17.89  Actual value: 18.50
No. 43  Predicted values: 38.34  Actual value: 33.10
No. 44  Predicted values: 23.83  Actual value: 25.00
No. 45  Predicted values: 49.20  Actual value: 50.00
No. 46  Predicted values: 13.21  Actual value: 13.50
No. 47  Predicted values: 48.34  Actual value: 50.00
No. 48  Predicted values: 11.99  Actual value: 12.10
No. 49  Predicted values: 12.14  Actual value: 11.30
No. 50  Predicted values: 22.63  Actual value: 21.00
No. 51  Predicted values: 21.88  Actual value: 21.20
No. 52  Predicted values: 18.35  Actual value: 18.50
No. 53  Predicted values: 19.64  Actual value: 18.20
No. 54  Predicted values: 8.24   Actual value: 10.90
No. 55  Predicted values: 26.19  Actual value: 23.20
No. 56  Predicted values: 8.71   Actual value: 11.80
No. 57  Predicted values: 23.11  Actual value: 16.80
No. 58  Predicted values: 19.99  Actual value: 18.30
No. 59  Predicted values: 21.21  Actual value: 16.80
No. 60  Predicted values: 49.10  Actual value: 50.00
No. 61  Predicted values: 16.41  Actual value: 14.50
No. 62  Predicted values: 22.02  Actual value: 22.80
No. 63  Predicted values: 14.31  Actual value: 11.50
No. 64  Predicted values: 46.68  Actual value: 50.00
No. 65  Predicted values: 17.36  Actual value: 18.50
No. 66  Predicted values: 32.03  Actual value: 31.70
No. 67  Predicted values: 20.96  Actual value: 20.30
No. 68  Predicted values: 26.76  Actual value: 30.80
No. 69  Predicted values: 24.85  Actual value: 29.10
No. 70  Predicted values: 26.28  Actual value: 23.90
No. 71  Predicted values: 20.24  Actual value: 16.10
No. 72  Predicted values: 19.00  Actual value: 22.60
No. 73  Predicted values: 27.35  Actual value: 31.50
No. 74  Predicted values: 17.18  Actual value: 15.60
No. 75  Predicted values: 20.23  Actual value: 20.00
No. 76  Predicted values: 21.59  Actual value: 23.80
No. 77  Predicted values: 16.72  Actual value: 13.00
No. 78  Predicted values: 30.50  Actual value: 28.60
No. 79  Predicted values: 14.19  Actual value: 14.00
No. 80  Predicted values: 15.49  Actual value: 17.10
No. 81  Predicted values: 14.78  Actual value: 17.30
No. 82  Predicted values: 20.72  Actual value: 19.60
No. 83  Predicted values: 31.39  Actual value: 25.00
No. 84  Predicted values: 21.41  Actual value: 19.70
No. 85  Predicted values: 23.09  Actual value: 23.00
No. 86  Predicted values: 21.56  Actual value: 20.10
No. 87  Predicted values: 22.46  Actual value: 24.40
No. 88  Predicted values: 10.60  Actual value: 5.60
No. 89  Predicted values: 26.01  Actual value: 26.20
No. 90  Predicted values: 14.71  Actual value: 13.10
No. 91  Predicted values: 11.50  Actual value: 8.30
No. 92  Predicted values: 13.44  Actual value: 8.50
No. 93  Predicted values: 24.07  Actual value: 23.90
No. 94  Predicted values: 31.20  Actual value: 28.70
No. 95  Predicted values: 17.91  Actual value: 18.70
No. 96  Predicted values: 45.85  Actual value: 50.00
No. 97  Predicted values: 38.09  Actual value: 32.70
No. 98  Predicted values: 18.67  Actual value: 20.30
No. 99  Predicted values: 24.93  Actual value: 22.00
No. 100 Predicted values: 49.02  Actual value: 48.80
No. 101 Predicted values: 21.35  Actual value: 21.80
No. 102 Predicted values: 16.55  Actual value: 18.90
No. 103 Predicted values: 28.59  Actual value: 28.70
No. 104 Predicted values: 15.09  Actual value: 14.50
No. 105 Predicted values: 46.28  Actual value: 38.70
No. 106 Predicted values: 19.91  Actual value: 24.30
No. 107 Predicted values: 26.11  Actual value: 20.60
No. 108 Predicted values: 8.51   Actual value: 7.20
No. 109 Predicted values: 45.63  Actual value: 37.60
No. 110 Predicted values: 20.69  Actual value: 23.80
No. 111 Predicted values: 21.22  Actual value: 24.70
No. 112 Predicted values: 16.83  Actual value: 14.20
No. 113 Predicted values: 18.67  Actual value: 18.20
No. 114 Predicted values: 23.66  Actual value: 23.20
No. 115 Predicted values: 21.22  Actual value: 22.00
No. 116 Predicted values: 49.23  Actual value: 50.00
No. 117 Predicted values: 45.87  Actual value: 44.80
No. 118 Predicted values: 16.72  Actual value: 17.40
No. 119 Predicted values: 23.07  Actual value: 25.30
No. 120 Predicted values: 15.24  Actual value: 16.30
No. 121 Predicted values: 23.95  Actual value: 22.80
No. 122 Predicted values: 6.76   Actual value: 7.00
No. 123 Predicted values: 21.14  Actual value: 22.00
No. 124 Predicted values: 21.39  Actual value: 20.30
No. 125 Predicted values: 42.00  Actual value: 41.30
No. 126 Predicted values: 16.88  Actual value: 13.80

```

### 源代码

#### \_def.h

```
//
// Created by 沈星宇 on 2021/4/21.
//

#ifndef INC_6___DEF__H
#define INC_6___DEF__H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define TrainData 380   // Num of data in train
#define TestData 126    // Num of data in test
#define In 13           // Num of neurons in the input layer
#define Out 1           // Num of neurons in the output layer
#define Imp 40          // Num of neurons in the implicit layer
#define Imp2 40         // Num of neurons in the implicit layer

//OVERRIDE
#define TrainingTimes 40000
#define REQUIRED_MSE 0.5 //
#define UAlta 0.5      // Learning rate of Imp2 to Out
#define VAlta 0.3       // Learning rate between In to Imp
#define WAlta 0.2       // Learning rate of Imp to Imp2
//OVERRIDE

#endif //INC_6___DEF__H

```

#### head.h

```
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
    if ((fp1 = fopen(in, "r")) == NULL) {
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
    if ((fp2 = fopen(out, "r")) == NULL) {
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
    if ((fp = fopen(test_file_name, "r")) == NULL) {
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
```

### main.c

```
#include "head.h"

//
// Created by sxing on 2021/4/21.
//

// 程序参数 in.txt out.txt test.txt
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    read_data(argv[1], argv[2]);
    init_BP_network();
    train_network();
    test_network(argv[3]);

    return 0;
}

```

