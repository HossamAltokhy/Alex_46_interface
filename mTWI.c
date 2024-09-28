#include <avr/io.h>
#include "mTWI.h"

void init_TWI(char TWI_Address, char TWI_CLOCK) {
    TWAR = TWI_Address;
    TWBR = 18; // To generate 100KHz while TWPS bits are Zeros.
}

char TWI_M_Transmit(char SLA, char data) {
    char statusCode = 0;
    // Start Condition 
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x08) {
        return ERROR;
    }

    TWDR = SLA;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x18 && statusCode != 0x20) {
        return ERROR;
    }

    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x28 && statusCode != 0x30) {
        return ERROR;
    }

    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

return ERROR;
}

char TWI_M_Transmit_buf(char SLA, char* pData, char array_sz) {
    char statusCode = 0;
    // Start Condition 
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x08) {
        return ERROR;
    }

    TWDR = SLA;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x18 && statusCode != 0x20) {
        return ERROR;
    }

    for (int i = 0; i < array_sz; i++) {
        TWDR = *(pData + i);
        TWCR = (1 << TWINT) | (1 << TWEN);
        while (!(TWCR & (1 << TWINT)));
        statusCode = TWSR & 0xF8;
        if (statusCode != 0x28) {
            return ERROR;
        }
    }



    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

    return ERROR;
}

char TWI_S_Receive() {
    char statusCode = 0;
    // Ready to receive my Address.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x60 && statusCode != 0x70) {
        return ERROR;
    }
    // Ready to receive Data.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x80 && statusCode != 0x90) {
        return ERROR;
    }
    return TWDR;
}

char TWI_M_Receive(char SLA) {
    char data = 0;
    char statusCode = 0;
    // Start Condition 
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x08) {
        return ERROR;
    }
    // SLA + R 
    TWDR = SLA;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x40) {
        return ERROR;
    }
    // Get ACK ready 
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x50) {
        return ERROR;
    }
    data = TWDR;
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

    return data;
}

char TWI_S_Transmit(char data) {
    char statusCode = 0;
    // Ready to receive my Address.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0xA8) {
        return ERROR;
    }

    // SLAVE transmits data
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0xB8) {
        return ERROR;
    }
    return ERROR;
}

char TWI_S_Receive_buf(char *pData, char array_sz) {
    char statusCode = 0;
    // Ready to receive my Address.
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    statusCode = TWSR & 0xF8;
    if (statusCode != 0x60 && statusCode != 0x70) {
        return ERROR;
    }

    for (int i = 0; i < array_sz; i++) {
        // Ready to receive Data.
        TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
        while (!(TWCR & (1 << TWINT)));
        statusCode = TWSR & 0xF8;
        if (statusCode != 0x80 && statusCode != 0x90) {
            return ERROR;
        }
        *(pData + i) = TWDR;
    }


    return ERROR;
}