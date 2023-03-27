-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Mar 19, 2023 at 01:38 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `solar`
--

-- --------------------------------------------------------


--
-- Table structure for table `PV`
--

CREATE TABLE `PV` (
  `id` int(11) NOT NULL,
  `name` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `PV`
--

INSERT INTO `PV` (`id`, `name`) VALUES
(1, 'pv1'),
(2, 'pv2');

-- --------------------------------------------------------


--
-- Table structure for table `voltage`
--

CREATE TABLE `voltage` (
  `id` int(11) NOT NULL,
  `value` int(11) NOT NULL,
  `pv` int(11) NOT NULL,
  `date` date NOT NULL,
  `time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `voltage`
--

INSERT INTO `voltage` (`id`, `value`, `pv`, `date`, `time`) VALUES
(1, 30, 1, '2023-03-15', '08:17:08'),
(2, 40, 2, '2023-03-16', '08:17:32'),
(3, 30, 3, '2023-03-16', '08:17:32');

--
-- Indexes for dumped tables
--
--
-- Indexes for table `current`
--
ALTER TABLE `current`
  ADD PRIMARY KEY (`id`),
  ADD KEY `pv` (`pv`);

--
-- Indexes for table `PV`
--
ALTER TABLE `PV`
  ADD PRIMARY KEY (`id`);


--
-- Indexes for table `voltage`
--
ALTER TABLE `voltage`
  ADD PRIMARY KEY (`id`),
  ADD KEY `pv` (`pv`);

--
-- AUTO_INCREMENT for dumped tables
--
--
-- AUTO_INCREMENT for table `current`
--
ALTER TABLE `current`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;


--
-- AUTO_INCREMENT for table `PV`
--
ALTER TABLE `PV`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;


--
-- AUTO_INCREMENT for table `voltage`
--
ALTER TABLE `voltage`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
