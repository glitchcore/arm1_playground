arm-none-eabi-as -march=armv2 -mcpu=arm2 main.s -o app.elf
arm-none-eabi-objcopy -O binary -S app.elf app.bin