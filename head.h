//
// Created by Sxing on 04/10/2021.
//

#ifndef INC_5__HEAD_H
#define INC_5__HEAD_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define K 3 // num of categories of iris
#define num_of_dim // num of dimension
#define MAX_ROUNDS 100 // maximum number of iterations

typedef enum {
    True = 1,
    False = 0
} bool;

typedef struct {
    double length_of_sepal;
    double width_of_sepal;
    double length_of_petal;
    double width_of_petal;
    char name_of_iris[30];
    int clusterID;
} Iris;
typedef struct {
    char iris_name[30];
    double accuracy;
} test_result;

int is_continue; // is or not continue
Iris iris[151]; // data
//Iris iris_copy[151]; // a copy of iris for verifying
Iris cluster_center[K]; // K set of clusters.
Iris new_center[K]; // a new copy
int num_of_data;
int cluster_center_init_index[K]; // the index of the data point originally used for each cluster center
double distance_from_center[K]; // distance from center for each point.
int data_size_per_cluster[K]; // total number of samples within each cluster
test_result testResults[K]; //
double total_accuracy;


bool inputs(char file_name[]) {
    FILE *fp;
    char name_of_iris[30];
    if ((fp = fopen(file_name, "rb")) == NULL) {
        return False;
    }
    int count = 0;
    while (!feof(fp)) {
        fscanf(fp, "%lf,%lf,%lf,%lf,%s", &iris[count].length_of_sepal, &iris[count].width_of_sepal,
               &iris[count].length_of_petal, &iris[count].width_of_petal, iris[count].name_of_iris);
        iris[count].clusterID = -1;
        count++;
    }
    num_of_data = count;
    fclose(fp);
    return True;
}

void init_cluster() {
    int random;
    srand((unsigned) time(NULL));
    for (int i = 0; i < K; ++i) {
        cluster_center_init_index[i] = -1;
    }
    for (int i = 0; i < K; ++i) {
        random = rand() % (num_of_data - 1);
        int j = 0;
        while (j < i) {
            if (random == cluster_center_init_index[j]) {
                random = rand() % (num_of_data);
                j = 0;
            } else {
                j++;
            }
        }
        cluster_center_init_index[i] = random;
    }
    for (int i = 0; i < K; ++i) {
        cluster_center[i].length_of_sepal = iris[cluster_center_init_index[i]].length_of_sepal;
        cluster_center[i].length_of_petal = iris[cluster_center_init_index[i]].length_of_petal;
        cluster_center[i].width_of_sepal = iris[cluster_center_init_index[i]].width_of_sepal;
        cluster_center[i].width_of_petal = iris[cluster_center_init_index[i]].width_of_petal;
        cluster_center[i].clusterID = i;
        iris[cluster_center_init_index[i]].clusterID = i;
    }
}

void partition_4_all_point_one_cluster();

void cal_cluster_center();

void KMeans() {
    int rounds;
    for (rounds = 0; rounds < MAX_ROUNDS; ++rounds) {
        printf("\nRounds: %d\n", rounds + 1);
        partition_4_all_point_one_cluster();
        cal_cluster_center();
        if (is_continue == 0) {
            printf("\nClustering is completed after %d times of clustering\n", rounds + 1);
            break;
        }
    }
}

void cal_distance_2_one_centers(int pointID, int centerID) {
    double x1 = pow(iris[pointID].length_of_sepal - cluster_center[centerID].length_of_sepal, 2.0);
    double x2 = pow(iris[pointID].length_of_petal - cluster_center[centerID].length_of_petal, 2.0);
    double x3 = pow(iris[pointID].width_of_sepal - cluster_center[centerID].width_of_sepal, 2.0);
    double x4 = pow(iris[pointID].width_of_petal - cluster_center[centerID].width_of_petal, 2.0);
    distance_from_center[centerID] = sqrt(x1 + x2 + x3 + x4);
}

void cal_distance_2_all_centers(int pointID) {
    for (int i = 0; i < K; ++i) {
        cal_distance_2_one_centers(pointID, i);
    }
}

void partition_4_one_point(int pointID) {
    int min_index = 0;
    double min_value = distance_from_center[0];
    for (int i = 0; i < K; ++i) {
        if (distance_from_center[i] < min_value) {
            min_value = distance_from_center[i];
            min_index = i;
        }
    }
    iris[pointID].clusterID = cluster_center[min_index].clusterID;
}

void partition_4_all_point_one_cluster() {
    for (int i = 0; i < num_of_data; ++i) {

        cal_distance_2_all_centers(i);
        partition_4_one_point(i);

    }
}

void compare_new_old_cluster_center();

void cal_cluster_center() {
    memset(new_center, 0, sizeof(new_center));
    memset(data_size_per_cluster, 0, sizeof(data_size_per_cluster));
    for (int i = 0; i < num_of_data; ++i) {
        new_center[iris[i].clusterID].length_of_sepal += iris[i].length_of_sepal;
        new_center[iris[i].clusterID].length_of_petal += iris[i].length_of_petal;
        new_center[iris[i].clusterID].width_of_sepal += iris[i].width_of_sepal;
        new_center[iris[i].clusterID].width_of_petal += iris[i].width_of_petal;
        data_size_per_cluster[iris[i].clusterID]++;
    }
    for (int i = 0; i < K; ++i) {
        if (data_size_per_cluster[i] != 0) {
            new_center[i].length_of_sepal = new_center[i].length_of_sepal / (double) data_size_per_cluster[i];
            new_center[i].length_of_petal = new_center[i].length_of_petal / (double) data_size_per_cluster[i];
            new_center[i].width_of_sepal = new_center[i].width_of_sepal / (double) data_size_per_cluster[i];
            new_center[i].width_of_petal = new_center[i].width_of_petal / (double) data_size_per_cluster[i];
            printf("cluster %d point cnt: %d\n", i, data_size_per_cluster[i]);
            printf("cluster %d center: length_of_sepal: %.2lf, width_of_sepal: %.2lf, length_of_petal: %.2lf, width_of_petal: %.2lf\n",
                   i, new_center[i].length_of_sepal, new_center[i].width_of_sepal, new_center[i].length_of_petal,
                   new_center[i].width_of_petal);
        } else {
            printf(" cluster %d count is zero\n", i);
        }
    }
    compare_new_old_cluster_center();
    for (int i = 0; i < K; ++i) {
        cluster_center[i].length_of_sepal = new_center[i].length_of_sepal;
        cluster_center[i].width_of_sepal = new_center[i].width_of_sepal;
        cluster_center[i].length_of_petal = new_center[i].length_of_petal;
        cluster_center[i].width_of_petal = new_center[i].width_of_petal;
        cluster_center[i].clusterID = i;
    }
    for (int i = 0; i < num_of_data; ++i) {
        iris->clusterID = -1;
    }
}

void compare_new_old_cluster_center() {
    is_continue = 0;
    for (int i = 0; i < K; ++i) {
        if (cluster_center[i].length_of_sepal != new_center[i].length_of_sepal ||
            cluster_center[i].width_of_sepal != new_center[i].width_of_sepal ||
            cluster_center[i].length_of_petal != new_center[i].length_of_petal ||
            cluster_center[i].width_of_petal != new_center[i].width_of_petal) {
            is_continue = 1;
            break;
        }
    }
}

void output_accuracy() {

    int category[K][K + 3] = {0}; // row as the hits of one species, 3 species in total.
    // index k is the associated cluster_ID, index k+1 is the associated sample count, index k+2 is the total count.
    for (int j = 0; j < num_of_data; ++j) {
        if (strcmp(iris[j].name_of_iris, "Iris-setosa") == 0) {
            category[0][iris[j].clusterID]++;
        } else if (strcmp(iris[j].name_of_iris, "Iris-versicolor") == 0) {
            category[1][iris[j].clusterID]++;
        } else if (strcmp(iris[j].name_of_iris, "Iris-virginica") == 0) {
            category[2][iris[j].clusterID]++;
        }
    }
    for (int i = 0; i < K; ++i) {
        int max = 0;
        int index_max = 0;
        int sum = 0;
        for (int j = 0; j < K; ++j) {
            sum += category[i][j];
            if (max < category[i][j]) {
                max = category[i][j];
                index_max = j;
            }
        }
        category[i][K] = index_max;
        category[i][K + 1] = max;
        category[i][K + 2] = sum;
    }

    strcpy(testResults[0].iris_name, "Iris-setosa");
    strcpy(testResults[1].iris_name, "Iris-versicolor");
    strcpy(testResults[2].iris_name, "ris-virginica");
    int total_sum = 0, total_correct = 0;
    for (int i = 0; i < K; ++i) {
        testResults[i].accuracy = (double) category[i][K + 1] / category[i][K + 2];
        total_sum += category[i][K + 2];
        total_correct += category[i][K + 1];
    }
    total_accuracy = (double) total_correct / total_sum;

}

void verify(char *input, char *output) {
    FILE *fp;
    char name_of_iris[30];
    fp = fopen(output, "w");
    int count = 0;
    while (count < num_of_data) {
        fprintf(fp, "%-4.2lf,%-4.2lf,%-4.2lf,%-4.2lf,%-20s,%d\n", iris[count].length_of_sepal,
                iris[count].width_of_sepal,
                iris[count].length_of_petal, iris[count].width_of_petal, iris[count].name_of_iris,
                iris[count].clusterID);
        count++;
    }
    output_accuracy();
    fprintf(fp, "\n");
    for (int i = 0; i < K; ++i) {
        fprintf(fp, "Category: %-20s,Accuracy: %.2lf%%\n", testResults[i].iris_name, testResults[i].accuracy * 100);
    }
    printf("Result saved in %s\n", output);
    printf("Total accuracy: %.2lf%%\n", total_accuracy * 100);
    printf("From Database: %s\n", input);


}

#endif //INC_5__HEAD_H
