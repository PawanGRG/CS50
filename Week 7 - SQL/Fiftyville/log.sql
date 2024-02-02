-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Theft took place on July 28
-- Theft took place on Humphrey Street

----------------------------- Lets see the people's table -----------------------------
SELECT * FROM people


----------------------------- Lets see the crime report -----------------------------
SELECT * FROM crime_scene_report


----------------------------- We know the crime took place on July 28 on Humprey Street -----------------------------
SELECT * FROM crime_scene_report WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-- | 297 | 2021 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.


----------------------------- We knew there were 3 witnesses, lets have a look at the witness table ----------------------------------
SELECT * FROM interviews WHERE month = 7 and day = 28;

 -- | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

----------------------------- Lets have a look at the bakery security logs on the July 18 on the 10th hour -----------------------------
 SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour >= 10;

                      -- So it could be --
                    
-- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
-- | 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58       |


----------------------------- Lets cross reference it and get their names -----------------------------
SELECT people.name, people.license_plate
FROM people JOIN bakery_security_logs
ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.activity = 'exit';

-- +---------+---------------+
-- |  name   | license_plate |
-- +---------+---------------+
-- | Vanessa | 5P2BI95       |
-- | Bruce   | 94KL13X       |
-- | Barry   | 6P58WS2       |
-- | Luca    | 4328GD8       |
-- | Sofia   | G412CB7       |
-- | Iman    | L93JTIZ       |
-- | Diana   | 322W7JE       |
-- | Kelsey  | 0NTHK55       |
-- | Taylor  | 1106N58       |
-- +---------+---------------+
--------------------------------------------------------------------------------------------------------------------------------

 -- | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

----------------------------- Lets have a look at the ATM transactions on the 28th of July on Leggett Street withdraws -----------------------------
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

                                -- So it could be --
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+

----------------------------- Lets cross reference with the names -----------------------------
SELECT people.name, atm_transactions.account_number
FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';


-- +---------+----------------+
-- |  name   | account_number |
-- +---------+----------------+
-- | Bruce   | 49610011       |
-- | Diana   | 26013199       |
-- | Brooke  | 16153065       |
-- | Kenny   | 28296815       |
-- | Iman    | 25506511       |
-- | Luca    | 28500762       |
-- | Taylor  | 76054385       |
-- | Benista | 81061156       |
-- +---------+----------------+

-------------------------------------------------------------------------------------------------------------------------------------------------

-- | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--                                        In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville
--                                        tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

----------------------------- Lets see the phone calls on the 28th of July that lasted less than a minute -----------------------------
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;
                           -- So it could be --
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
-- +-----+----------------+----------------+------+-------+-----+----------+

------------------ Cross Reference --------------------
SELECT phone_calls.caller, people.name
FROM phone_calls JOIN people
ON phone_calls.caller = people.phone_number
WHERE month = 7 AND day = 28 AND duration < 60;

-- +----------------+---------+
-- |     caller     |  name   |
-- +----------------+---------+
-- | (130) 555-0289 | Sofia   |
-- | (499) 555-9472 | Kelsey  |
-- | (367) 555-5533 | Bruce   |
-- | (499) 555-9472 | Kelsey  |
-- | (286) 555-6063 | Taylor  |
-- | (770) 555-1861 | Diana   |
-- | (031) 555-6622 | Carina  |
-- | (826) 555-1652 | Kenny   |
-- | (338) 555-6650 | Benista |
-- +----------------+---------+


SELECT phone_calls.receiver, people.name
FROM phone_calls JOIN people
ON phone_calls.receiver = people.phone_number
WHERE month = 7 AND day = 28 AND duration < 60;

-- +----------------+------------+
-- |    receiver    |    name    |
-- +----------------+------------+
-- | (996) 555-8899 | Jack       |
-- | (892) 555-8872 | Larry      |
-- | (375) 555-8161 | Robin      |
-- | (717) 555-1342 | Melissa    |
-- | (676) 555-6554 | James      |
-- | (725) 555-3243 | Philip     |
-- | (910) 555-3251 | Jacqueline |
-- | (066) 555-9701 | Doris      |
-- | (704) 555-2131 | Anna       |
-- +----------------+------------+



 SELECT * FROM flights WHERE month = 7 AND day = 29 ORDER BY hour ASC;
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+

SELECT people.name, flights.id
FROM flights
JOIN passengers ON flights.id = passengers.flight_id
JOIN people ON passengers.passport_number = people.passport_number
WHERE flights.month = 7
AND flights.day = 29
AND flights.origin_airport_id = 8
AND flights.hour = 8;

-- +--------+----+
-- |  name  | id |
-- +--------+----+
-- | Doris  | 36 |
-- | Sofia  | 36 |
-- | Bruce  | 36 |
-- | Edward | 36 |
-- | Kelsey | 36 |
-- | Taylor | 36 |
-- | Kenny  | 36 |
-- | Luca   | 36 |
-- +--------+----+

