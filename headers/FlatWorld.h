#pragma once

class FlatWorld{
public: 
    float minBodySize = 0.01f * 0.01f; 
    float maxBodySize = 64.0f * 64.0f;

    float minDensity = 0.5f; // g/cm3
    float maxDensity = 21.4f; // g/cm3
};
