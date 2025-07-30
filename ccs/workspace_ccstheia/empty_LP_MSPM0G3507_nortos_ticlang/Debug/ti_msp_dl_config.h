/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMG8
#define PWM_MOTOR_INST_IRQHandler                               TIMG8_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMG8_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                          4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C0_PIN                                     DL_GPIO_PIN_26
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM59)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM59_PF_TIMG8_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C1_PIN                                     DL_GPIO_PIN_27
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM60)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM60_PF_TIMG8_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                          (1199U)




/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C0
#define I2C_0_INST_IRQHandler                                    I2C0_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C0_INT_IRQn
#define I2C_0_BUS_SPEED_HZ                                                400000
#define GPIO_I2C_0_SDA_PORT                                                GPIOA
#define GPIO_I2C_0_SDA_PIN                                         DL_GPIO_PIN_0
#define GPIO_I2C_0_IOMUX_SDA                                      (IOMUX_PINCM1)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                       IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOA
#define GPIO_I2C_0_SCL_PIN                                         DL_GPIO_PIN_1
#define GPIO_I2C_0_IOMUX_SCL                                      (IOMUX_PINCM2)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                       IOMUX_PINCM2_PF_I2C0_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                            4000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_4_MHZ_9600_BAUD                                         (26)
#define UART_0_FBRD_4_MHZ_9600_BAUD                                          (3)





/* Port definition for Pin Group LED1 */
#define LED1_PORT                                                        (GPIOB)

/* Defines for PIN_22: GPIOB.22 with pinCMx 50 on package pin 21 */
#define LED1_PIN_22_PIN                                         (DL_GPIO_PIN_22)
#define LED1_PIN_22_IOMUX                                        (IOMUX_PINCM50)
/* Port definition for Pin Group motorA */
#define motorA_PORT                                                      (GPIOB)

/* Defines for PIN_0: GPIOB.13 with pinCMx 30 on package pin 1 */
#define motorA_PIN_0_PIN                                        (DL_GPIO_PIN_13)
#define motorA_PIN_0_IOMUX                                       (IOMUX_PINCM30)
/* Defines for PIN_1: GPIOB.12 with pinCMx 29 on package pin 64 */
#define motorA_PIN_1_PIN                                        (DL_GPIO_PIN_12)
#define motorA_PIN_1_IOMUX                                       (IOMUX_PINCM29)
/* Port definition for Pin Group motorB */
#define motorB_PORT                                                      (GPIOB)

/* Defines for PIN_2: GPIOB.10 with pinCMx 27 on package pin 62 */
#define motorB_PIN_2_PIN                                        (DL_GPIO_PIN_10)
#define motorB_PIN_2_IOMUX                                       (IOMUX_PINCM27)
/* Defines for PIN_3: GPIOB.11 with pinCMx 28 on package pin 63 */
#define motorB_PIN_3_PIN                                        (DL_GPIO_PIN_11)
#define motorB_PIN_3_IOMUX                                       (IOMUX_PINCM28)
/* Port definition for Pin Group ENCODERL */
#define ENCODERL_PORT                                                    (GPIOB)

/* Defines for PIN_4: GPIOB.17 with pinCMx 43 on package pin 14 */
// pins affected by this interrupt request:["PIN_4"]
#define ENCODERL_INT_IRQN                                       (GPIOB_INT_IRQn)
#define ENCODERL_INT_IIDX                       (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define ENCODERL_PIN_4_IIDX                                 (DL_GPIO_IIDX_DIO17)
#define ENCODERL_PIN_4_PIN                                      (DL_GPIO_PIN_17)
#define ENCODERL_PIN_4_IOMUX                                     (IOMUX_PINCM43)
/* Defines for PIN_5: GPIOB.18 with pinCMx 44 on package pin 15 */
#define ENCODERL_PIN_5_PIN                                      (DL_GPIO_PIN_18)
#define ENCODERL_PIN_5_IOMUX                                     (IOMUX_PINCM44)
/* Port definition for Pin Group ENCODERR */
#define ENCODERR_PORT                                                    (GPIOA)

/* Defines for PIN_6: GPIOA.16 with pinCMx 38 on package pin 9 */
// pins affected by this interrupt request:["PIN_6"]
#define ENCODERR_INT_IRQN                                       (GPIOA_INT_IRQn)
#define ENCODERR_INT_IIDX                       (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define ENCODERR_PIN_6_IIDX                                 (DL_GPIO_IIDX_DIO16)
#define ENCODERR_PIN_6_PIN                                      (DL_GPIO_PIN_16)
#define ENCODERR_PIN_6_IOMUX                                     (IOMUX_PINCM38)
/* Defines for PIN_7: GPIOA.17 with pinCMx 39 on package pin 10 */
#define ENCODERR_PIN_7_PIN                                      (DL_GPIO_PIN_17)
#define ENCODERR_PIN_7_IOMUX                                     (IOMUX_PINCM39)
/* Defines for out1: GPIOB.6 with pinCMx 23 on package pin 58 */
#define Trace_out1_PORT                                                  (GPIOB)
#define Trace_out1_PIN                                           (DL_GPIO_PIN_6)
#define Trace_out1_IOMUX                                         (IOMUX_PINCM23)
/* Defines for out2: GPIOB.7 with pinCMx 24 on package pin 59 */
#define Trace_out2_PORT                                                  (GPIOB)
#define Trace_out2_PIN                                           (DL_GPIO_PIN_7)
#define Trace_out2_IOMUX                                         (IOMUX_PINCM24)
/* Defines for out3: GPIOB.8 with pinCMx 25 on package pin 60 */
#define Trace_out3_PORT                                                  (GPIOB)
#define Trace_out3_PIN                                           (DL_GPIO_PIN_8)
#define Trace_out3_IOMUX                                         (IOMUX_PINCM25)
/* Defines for out4: GPIOB.9 with pinCMx 26 on package pin 61 */
#define Trace_out4_PORT                                                  (GPIOB)
#define Trace_out4_PIN                                           (DL_GPIO_PIN_9)
#define Trace_out4_IOMUX                                         (IOMUX_PINCM26)
/* Defines for out5: GPIOA.12 with pinCMx 34 on package pin 5 */
#define Trace_out5_PORT                                                  (GPIOA)
#define Trace_out5_PIN                                          (DL_GPIO_PIN_12)
#define Trace_out5_IOMUX                                         (IOMUX_PINCM34)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOB)

/* Defines for PIN_8: GPIOB.21 with pinCMx 49 on package pin 20 */
#define KEY_PIN_8_PIN                                           (DL_GPIO_PIN_21)
#define KEY_PIN_8_IOMUX                                          (IOMUX_PINCM49)
/* Defines for PIN_9: GPIOB.27 with pinCMx 58 on package pin 29 */
#define KEY_PIN_9_PIN                                           (DL_GPIO_PIN_27)
#define KEY_PIN_9_IOMUX                                          (IOMUX_PINCM58)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_I2C_0_init(void);
void SYSCFG_DL_UART_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
