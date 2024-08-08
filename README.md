
# Reservify

**Abstract**: Simplified reservation simulator in C++.

**Document language/documentation language**: Portuguese.

**Programming language**: C++.

**Autor**: Kevyn Marques, Julia Campanelli Granja.

---

### Reservify

Reservify is a simplified reservation simulator, where the user have contact with a protected program stuffed of security confirmations for each operation and also subjected by several case tests, even it's had being constructed in a basic language, C++.

### Portability

Take a look at the mesa.hpp file, which is the basis of our simulator (disregarding the lista.hpp file, which is basically the implementation of a cadastral list, which makes use of an object such as info, in this case the class "mesa"). New attributes can be easily added by simply creating new getter and setter functions to ensure data integrity. Additionally, by moving up one level to the restaurant.hpp file, you can update existing functions or create new ones to leverage these new attributes. The entire structure is designed to allow modifications to be made with minimal effort.

### Architecture

The program is basically based on a simple cadastral list as data structure.

**General Overview of the Structures**

<img src="Media/image_overview_structures.png" alt="Diagrama do Esquema Geral" width="50%">

