

https://github.com/berinackr/Vaccine_Registration_Program/assets/101141003/6f4dbc42-a2fe-4e6c-a8f9-635c4bee3f1d


# VACCINE REGISTRATION PROGRAM

This project is a program that will streamline vaccination processes by keeping users' vaccination records. In the program, each of the operations is written as a separate function. It is then called and used at relevant places within the program.

The program works by making selections that guide the user on the terminal. A suitable menu has been created to perform the desired operations and the processes continue until exit.


## Constraints

- A file named "database.txt" has been created in the project folder and when the program is opened, it reads from this file. If there is a user registered in the file, it reads this user. If the file is empty it does nothing.
- Any update made to the program also changes the file.
- Each record is kept sequentially on a single line in the file. It is recorded using one space between each information. (Ex: AB24 Ali Yılmaz 35 Ankara 01.06.2020 1 X)
- There are 2 different vaccines, X and Y. Users will be able to receive only one of these vaccines. Therefore, both X and Y vaccines cannot be vaccinated.
- Users will be able to receive a maximum of 2 vaccines in total. Requests for new vaccinations from users who have had 2 vaccinations will be rejected.
- People under the age of 18 will not be able to request vaccination.
- At least 1 month must have passed since the last vaccination.


The user must be able to perform the following operations through the program:
- Registering to the system. When the user registers to the system, the following information will be received:

    - ID (4-digit code/must be unique to each user): The ID      format is HHRR (H: Letter R: Number) and it should be checked whether the entry is in the correct format.
    - Name
    - Surname
    - Age
    - City
- During the new registration, in addition to the above information, the information provided below will be created with default values. This information will later be used in vaccination registration.
    - Last vaccination date: 01.06.2020
    - Vaccine dose number: 0
    - Vaccine name: NULL
- Viewing the record from the system. All the user's information will be displayed.
- Updating the record in the system. Any information provided by the user when registering to the system (except vaccination information) can be updated.
- Registering for a new vaccination. The system includes two different vaccines. These are vaccines X and Y.
    - The user should be presented with these two options
    - You should be asked to choose one of the options
    - The suitability of the selection made should be checked
    - If appropriate, a vaccination record should be created
    - If it is not suitable, the user must be informed and the selection must be made again.

## Used technologies

**Programming Language:** C++

**Structures used:** Array, String, Structures, File I/O

## Program Images

![menu](https://github.com/berinackr/Vaccine_Registration_Program/assets/101141003/66a2df12-3107-4871-bda0-0c696d32622e)
![register](https://github.com/berinackr/Vaccine_Registration_Program/assets/101141003/ada91f75-580d-4e70-b1cc-b52bc10151d9)
![user_info](https://github.com/berinackr/Vaccine_Registration_Program/assets/101141003/34f7aa53-72d5-4dbd-93ce-7b6164806e58)
![all_register](https://github.com/berinackr/Vaccine_Registration_Program/assets/101141003/0d7f9dcf-8bbf-4ef5-93f4-f491adffe944)
