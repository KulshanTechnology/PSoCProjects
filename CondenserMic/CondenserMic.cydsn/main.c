/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    int16 ADC_Result;
    uint8 I2Cbuffer[2];
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Opamp_Start();
    I2C_Start();
    I2C_EzI2CSetBuffer1(2, 2, I2Cbuffer);
    ADC_Start();
    ADC_StartConvert();
    
    for(;;)
    {
        /* Place your application code here. */
        if(ADC_IsEndConversion(ADC_RETURN_STATUS))
        {
            //ADC_Result = ADC_CountsTo_mVolts(0,ADC_GetResult16(0));
            
            ADC_Result = ADC_GetResult16(0);
            
            /* Saturation at lower end */
            if(ADC_Result <0)
            {
                ADC_Result = 0;
            }
            
            I2Cbuffer[0] = HI8(ADC_Result);
            I2Cbuffer[1] = LO8(ADC_Result);
        }
    }
}

/* [] END OF FILE */
