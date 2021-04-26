//
// Created by 沈星宇 on 2021/4/21.
//

#ifndef INC_6___DEF__H
#define INC_6___DEF__H

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define TrainData 380   // Num of data in train
#define TestData 126    // Num of data in test
#define In 13           // Num of neurons in the input layer
#define Out 1           // Num of neurons in the output layer
#define Imp 40          // Num of neurons in the implicit layer
#define Imp2 40         // Num of neurons in the implicit layer

//OVERRIDE
#define TrainingTimes 40000
#define UAlta 0.2      // Learning rate of Imp2 to Out
#define VAlta 0.2       // Learning rate between In to Imp
#define WAlta 0.1       // Learning rate of Imp to Imp2
//OVERRIDE

#endif //INC_6___DEF__H
