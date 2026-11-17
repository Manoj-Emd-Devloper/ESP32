#define LED_PIN 2

// Task 1: LED ON
void LED_ON_Task(void *pvParameters)
{
    while (1)
    {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("LED ON");

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

// Task 2: LED OFF
void LED_OFF_Task(void *pvParameters)
{
    while (1)
    {
        digitalWrite(LED_PIN, LOW);
        Serial.println("LED OFF");

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);

    // Create Task 1
    xTaskCreate(
        LED_ON_Task,
        "LED ON",
        2048,
        NULL,
        1,
        NULL
    );

    // Create Task 2
    xTaskCreate(
        LED_OFF_Task,
        "LED OFF",
        2048,
        NULL,
        1,
        NULL
    );
}

void loop()
{
}



// #define LED_PIN 2

// // FreeRTOS LED Blink Task
// void LED_Blink_Task(void *pvParameters)
// {
//     pinMode(LED_PIN, OUTPUT);

//     while (1)
//     {
//         digitalWrite(LED_PIN, HIGH);
//         vTaskDelay(pdMS_TO_TICKS(1000));

//         digitalWrite(LED_PIN, LOW);
//         vTaskDelay(pdMS_TO_TICKS(1000));
//     }
// }

// void setup()
// {
//     Serial.begin(115200);

//     // Create FreeRTOS Task
//     xTaskCreate(
//         LED_Blink_Task,     // Task function
//         "LED Blink Task",   // Task name
//         2048,               // Stack size
//         NULL,               // Parameters
//         1,                  // Priority
//         NULL                // Task handle
//     );
// }

// void loop()
// {
//     // Arduino loop task remains idle
// }



// #define LED_PIN 2  // Built-in LED (GPIO 2)

// void setup()
// {
//     pinMode(LED_PIN, OUTPUT);
// }

// void loop()
// {
//     digitalWrite(LED_PIN, HIGH);  // LED ON
//     delay(1000);

//     digitalWrite(LED_PIN, LOW);   // LED OFF
//     delay(1000);
// }