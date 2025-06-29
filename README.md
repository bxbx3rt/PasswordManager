# PasswordManager
(Again, but better) a password manager based on c++
English:
This program is designed in C++, pending future implementations such as new features and a graphical interface.

The operation is quite basic. First, if the data folder doesn't exist, it prompts the user to register by entering a username and password.

When the user registers, the program stores the username and password hash, but the physical password is never manipulated. To verify access, the program hashes the login password. If user && hash_psswd match, it allows access.

Subsequently, when new passwords are added to the manager, they are stored in a file. This file (the content) is encrypted with the SHA-256 algorithm. The content cannot be obtained unless the user logs in with the original password hash.

That is, the key is a combination of the original hash and another generated when entering the key. Only by logging in can the plain text be viewed.

If the user forgets their password or username, they cannot manipulate it or create a new hash. You will simply need to delete the entire data folder and start over.

 --
 Español:
 Este programa está diseñado en C++, pendiente de futuras implementaciones como nuevas funcionalidades y una interfaz gráfica.

El funcionamiento es bastante básico, en primer lugar si la carpeta data no existe pide al usuario una vez registrarse poniendo usuario y contraseña. 

El programa, al registrarse el usuario almacena el usuario y el Hash de la contraseña, pero nunca se manipula la contraseña en fisico. Para comprobar el acceso, el programa realiza un hash de la contraseña del login, si user && hash_psswd coinciden, permite el paso.

Posteriormente, al añadir nuevas contraseñas al gestor las almacena en un fichero, este fichero está encriptado (el contenido) con el algoritmo sha-256. No se puede obtener el contenido a no ser que se inicie sesion con el hash de la contraseña original.

Es decir, la clave es un compendio entre el hash original y otro generado al introducir la clave. Solo accediendo mediante el loggin se permite ver el texto plano.

Si el usuario olvidara su contraseña o su usuario, no podria manipular ni crear un hash nuevo. Simplemente, deberá de borrar la carpeta data entera y volver a empezar.
