#pragma once

#include <iostream>

static uint8_t length_table[256] = {
    4, // 1111
    5, // 2111
    6, // 3111
    7, // 4111
    5, // 1211
    6, // 2211
    7, // 3211
    8, // 4211
    6, // 1311
    7, // 2311
    8, // 3311
    9, // 4311
    7, // 1411
    8, // 2411
    9, // 3411
    10, // 4411
    5, // 1121
    6, // 2121
    7, // 3121
    8, // 4121
    6, // 1221
    7, // 2221
    8, // 3221
    9, // 4221
    7, // 1321
    8, // 2321
    9, // 3321
    10, // 4321
    8, // 1421
    9, // 2421
    10, // 3421
    11, // 4421
    6, // 1131
    7, // 2131
    8, // 3131
    9, // 4131
    7, // 1231
    8, // 2231
    9, // 3231
    10, // 4231
    8, // 1331
    9, // 2331
    10, // 3331
    11, // 4331
    9, // 1431
    10, // 2431
    11, // 3431
    12, // 4431
    7, // 1141
    8, // 2141
    9, // 3141
    10, // 4141
    8, // 1241
    9, // 2241
    10, // 3241
    11, // 4241
    9, // 1341
    10, // 2341
    11, // 3341
    12, // 4341
    10, // 1441
    11, // 2441
    12, // 3441
    13, // 4441
    5, // 1112
    6, // 2112
    7, // 3112
    8, // 4112
    6, // 1212
    7, // 2212
    8, // 3212
    9, // 4212
    7, // 1312
    8, // 2312
    9, // 3312
    10, // 4312
    8, // 1412
    9, // 2412
    10, // 3412
    11, // 4412
    6, // 1122
    7, // 2122
    8, // 3122
    9, // 4122
    7, // 1222
    8, // 2222
    9, // 3222
    10, // 4222
    8, // 1322
    9, // 2322
    10, // 3322
    11, // 4322
    9, // 1422
    10, // 2422
    11, // 3422
    12, // 4422
    7, // 1132
    8, // 2132
    9, // 3132
    10, // 4132
    8, // 1232
    9, // 2232
    10, // 3232
    11, // 4232
    9, // 1332
    10, // 2332
    11, // 3332
    12, // 4332
    10, // 1432
    11, // 2432
    12, // 3432
    13, // 4432
    8, // 1142
    9, // 2142
    10, // 3142
    11, // 4142
    9, // 1242
    10, // 2242
    11, // 3242
    12, // 4242
    10, // 1342
    11, // 2342
    12, // 3342
    13, // 4342
    11, // 1442
    12, // 2442
    13, // 3442
    14, // 4442
    6, // 1113
    7, // 2113
    8, // 3113
    9, // 4113
    7, // 1213
    8, // 2213
    9, // 3213
    10, // 4213
    8, // 1313
    9, // 2313
    10, // 3313
    11, // 4313
    9, // 1413
    10, // 2413
    11, // 3413
    12, // 4413
    7, // 1123
    8, // 2123
    9, // 3123
    10, // 4123
    8, // 1223
    9, // 2223
    10, // 3223
    11, // 4223
    9, // 1323
    10, // 2323
    11, // 3323
    12, // 4323
    10, // 1423
    11, // 2423
    12, // 3423
    13, // 4423
    8, // 1133
    9, // 2133
    10, // 3133
    11, // 4133
    9, // 1233
    10, // 2233
    11, // 3233
    12, // 4233
    10, // 1333
    11, // 2333
    12, // 3333
    13, // 4333
    11, // 1433
    12, // 2433
    13, // 3433
    14, // 4433
    9, // 1143
    10, // 2143
    11, // 3143
    12, // 4143
    10, // 1243
    11, // 2243
    12, // 3243
    13, // 4243
    11, // 1343
    12, // 2343
    13, // 3343
    14, // 4343
    12, // 1443
    13, // 2443
    14, // 3443
    15, // 4443
    7, // 1114
    8, // 2114
    9, // 3114
    10, // 4114
    8, // 1214
    9, // 2214
    10, // 3214
    11, // 4214
    9, // 1314
    10, // 2314
    11, // 3314
    12, // 4314
    10, // 1414
    11, // 2414
    12, // 3414
    13, // 4414
    8, // 1124
    9, // 2124
    10, // 3124
    11, // 4124
    9, // 1224
    10, // 2224
    11, // 3224
    12, // 4224
    10, // 1324
    11, // 2324
    12, // 3324
    13, // 4324
    11, // 1424
    12, // 2424
    13, // 3424
    14, // 4424
    9, // 1134
    10, // 2134
    11, // 3134
    12, // 4134
    10, // 1234
    11, // 2234
    12, // 3234
    13, // 4234
    11, // 1334
    12, // 2334
    13, // 3334
    14, // 4334
    12, // 1434
    13, // 2434
    14, // 3434
    15, // 4434
    10, // 1144
    11, // 2144
    12, // 3144
    13, // 4144
    11, // 1244
    12, // 2244
    13, // 3244
    14, // 4244
    12, // 1344
    13, // 2344
    14, // 3344
    15, // 4344
    13, // 1444
    14, // 2444
    15, // 3444
    16, // 4444
};