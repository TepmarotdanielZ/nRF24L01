# 1. nRF24Lo1 :

![image](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/cf88f439-4ad9-4b20-a680-f3a3c2186276)

The nRF24L01 is a wireless transceiver module, i.e. each module can both send & receive data. It works within the frequency of 2.4GHz. This frequency falls under the ISM band and is legal to use in most countries for engineering projects. The modules when operated efficiently can cover a distance of 100 meters.

![image](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/e6d5b25a-6853-44fc-a167-f4c527a6703b)

The second version of this module, i.e. nRF24L01 PA+LNA comes with an SMA connector, duck-antenna & special RFX2401C chip which integrates the PA + LNA. This range extender chip along with a duck-antenna helps the module achieve a significantly larger transmission range about 1000m. The PA stands for Power Amplifier which boosts the power of the signal being transmitted from the nRF24L01+ chip. The LNA stands for the Low-Noise Amplifier which takes the extremely weak and uncertain signal from the antenna and amplifies it to a more useful level.

The module operates at 3.3V but its SPI pins are 5V tolerable. Each module has an address range of 125 and every module can communicate with 6 other modules hence mesh networking can be established with this module. The NRF24L01 module works with the help of SPI communications hence you can use NRF24L01 with any microcontroller with SPI Pins like STM32 or Arduino Boards.

# 2. Pin Out :

![image](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/6d7785fd-8063-4a61-8fd3-1dabee6f1d30)

# 3. Configuration Transmitter (Tx) :

    . RCC : 

![image_2024-04-04_09-08-38](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/386afd42-2c1e-488c-bc31-079116cb200c)

    . SYS :

![image_2024-04-04_09-08-38](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/073bd54f-5b44-4bbd-98d9-99574ffb956b)


    . CLOCK :

![image_2024-04-04_09-09-04](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/5170551e-a206-40f1-aec6-88f121cdba64)

     . SPI1 :

![image_2024-04-04_09-09-33](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/641ef729-ff42-4b7d-8e71-b54ba0e5cc40)

     . GPOIO :

![image_2024-04-04_09-13-28](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/93aa56e5-f2ba-4212-be24-d124e0e5b070)

![image_2024-04-04_09-13-38](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/66e9e13c-650f-4057-8f83-ea00e9eaafd8)

     . CODE TX :

![image_2024-04-04_09-10-50](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/2004ca03-5f32-4f73-b03b-9bfd883560bd)

![image_2024-04-04_09-11-03](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/32c8bd5a-86ac-487b-bbe0-9346c3384a2a)

![image_2024-04-04_09-11-19](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/83a223f8-f9ff-4493-9375-d80e3d978ac6)

# 4. Configuration Receiver (Rx) :

    . RCC : 

![image_2024-04-04_09-14-35](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/bc0481e8-0961-4cc0-a83f-973820508718)

    . SYS :

![image_2024-04-04_09-14-47](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/967c73f0-f9e2-427b-b6e1-151591ae355b)

    . CLOCK :

![image_2024-04-04_09-09-04](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/5170551e-a206-40f1-aec6-88f121cdba64)

     . SPI1 :

![image_2024-04-04_09-20-56](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/bebf64b6-5aba-41ef-b534-4c4dc9024687)

     . GPOIO :

![image_2024-04-04_09-21-27](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/4acf6cae-dec4-4611-8c9d-498a7a243bf0)

![image_2024-04-04_09-21-39](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/3d2b09c1-0ea8-4b3a-b9b7-178466c212c7)

     . CODE TX :

![image_2024-04-04_09-22-30](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/be43e8fb-fe87-4e8f-b85e-562d3fdc6790)

![image_2024-04-04_09-22-40](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/e2cf4c03-bf05-4994-995f-8d48464ce489)

![image_2024-04-04_09-22-53](https://github.com/TepmarotdanielZ/nRF24L01/assets/139426571/b510c589-6461-42ab-9269-efe9c4266a91)

# 5. Schematic :
# 6. Result Testing :
