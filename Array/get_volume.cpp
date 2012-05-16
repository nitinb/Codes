#include <iostream>

using namespace std;

#define min(a, b) a > b ? b : a

void maximum_height(float *height, int num_of_buildings, float *max_store){
    max_store[num_of_buildings - 1] = -1;

    for(int i = num_of_buildings - 2; i >= 0; i--){
        int index = i + 1;
        while(index != - 1 && height[index] < height[i]){
            index = max_store[index];
        }

        if(index == -1){
            max_store[i] = index;
            continue;
        }

        if(height[i] <= height[index]){
            max_store[i] = index;
        }
    }
}

void print_array(float *max_store, int num_of_buildings){
    for(int i = 0; i < num_of_buildings; i++){
        std::cout << max_store[i] << " ";
    }
    std::cout << std::endl;
}

float get_volume(float *height, float *max_store, int num_of_buildings){
    float height_difference = 0.0;

    for(int i = 0; i < num_of_buildings; i++){
        // std::cout << "Processing building: " << i << std::endl;
        int index = max_store[i];
        if(index == -1){
            // Get tallest building
            for(int j = i + 1; j < num_of_buildings; j++){
                if(max_store[j] == -1){
                    index = j;
                    break;
                }
            }
        }

        if(index == -1){
           break;
        }

        float max_height = min(height[index], height[i]);
        for(int j = i + 1; j < index; j++){
            height_difference += max_height - height[j];
            // std::cout << "height diff: " << height_difference << std::endl;
        }
        i = index - 1;
    }

    return height_difference;
}

int main(){
    int num_of_buildings;

    std::cout << "Number of buildings: ";
    std::cin >> num_of_buildings;

    float height[num_of_buildings], max_store[num_of_buildings];
    for(int i = 0; i < num_of_buildings; i++){
        std::cin >> height[i];
    }

    maximum_height(height, num_of_buildings, max_store);
    print_array(max_store, num_of_buildings);

    float height_difference = get_volume(height, max_store, num_of_buildings);
    std::cout << "Height diff: " << height_difference << std::endl;
}
