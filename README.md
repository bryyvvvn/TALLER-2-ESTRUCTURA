Si es primera vez que se ejecuta el codigo, se crea un archivo "Clientes.txt" que servirÃ¡ para guardar la sesion para que al finalizar y 
despues iniciar nuevamente el codigo se pueda seguir atendiendo a los clientes que estaban en la cola.


Al ejecutar por primera vez el codigo, se lee el archivo "Bodega.txt" y se crean 75 objetos de la clase producto:

producto1: { Categoria:"Medicina"; subcategoria: "Analgesicos"; precio:"7.99"; id:"432432"}

producto2: { Categoria:"Medicina"; subcategoria: "Analgesicos"; precio:"7.99"; id:"345678"}

producto3: { Categoria:"Medicina"; subcategoria: "Analgesicos"; precio:"6.50"; id:"456789"}

producto4: { Categoria:"Medicina"; subcategoria: "Antisepticos"; precio:"6.99"; id:"154671"}
producto5: { Categoria:"Medicina"; subcategoria: "Antisepticos"; precio:"9.99"; id:"678901"}
producto6: { Categoria:"Medicina"; subcategoria: "Antisepticos"; precio:"5.50"; id:"789012"}
producto7: { Categoria:"Medicina"; subcategoria: "Antibioticos"; precio:"8.49"; id:"145345"}
producto8: { Categoria:"Medicina"; subcategoria: "Antibioticos"; precio:"12.99"; id:"901234"}
producto9: { Categoria:"Medicina"; subcategoria: "Antibioticos"; precio:"8.50"; id:"123456"}
producto10: { Categoria:"Medicina"; subcategoria: "Antipireticos"; precio:"5.49"; id:"243242"}
producto11: { Categoria:"Medicina"; subcategoria: "Antipireticos"; precio:"5.99"; id:"345678"}
producto12: { Categoria:"Medicina"; subcategoria: "Antipireticos"; precio:"4.50"; id:"456789"}
producto13: { Categoria:"Medicina"; subcategoria: "Antihistaminicos"; precio:"9.99"; id:"345433"}
producto14: { Categoria:"Medicina"; subcategoria: "Antihistaminicos"; precio:"8.99"; id:"678901"}
producto15: { Categoria:"Medicina"; subcategoria: "Antihistaminicos"; precio:"6.50"; id:"789012"}
producto16: { Categoria:"Dermatologico"; subcategoria: "Cremas Hidratantes"; precio:"8.99"; id:"463456"}
producto17: { Categoria:"Dermatologico"; subcategoria: "Cremas Hidratantes"; precio:"6.50"; id:"456789"}
producto18: { Categoria:"Dermatologico"; subcategoria: "Cremas Hidratantes"; precio:"8.75"; id:"567890"}
producto19: { Categoria:"Dermatologico"; subcategoria: "Protectores Solares"; precio:"9.99"; id:"678901"}
producto20: { Categoria:"Dermatologico"; subcategoria: "Protectores Solares"; precio:"5.50"; id:"789012"}
producto21: { Categoria:"Dermatologico"; subcategoria: "Protectores Solares"; precio:"7.75"; id:"890123"}
producto22: { Categoria:"Dermatologico"; subcategoria: "Tratamientos Antiarrugas"; precio:"12.99"; id:"901234"}
producto23: { Categoria:"Dermatologico"; subcategoria: "Tratamientos Antiarrugas"; precio:"8.50"; id:"123456"}
producto24: { Categoria:"Dermatologico"; subcategoria: "Tratamientos Antiarrugas"; precio:"10.75"; id:"234567"}
producto25: { Categoria:"Dermatologico"; subcategoria: "Limpiadores Faciales"; precio:"5.99"; id:"345678"}
producto26: { Categoria:"Dermatologico"; subcategoria: "Limpiadores Faciales"; precio:"4.50"; id:"456789"}
producto27: { Categoria:"Dermatologico"; subcategoria: "Limpiadores Faciales"; precio:"6.75"; id:"567890"}
producto28: { Categoria:"Dermatologico"; subcategoria: "Serum"; precio:"8.99"; id:"678901"}
producto29: { Categoria:"Dermatologico"; subcategoria: "Serum"; precio:"6.50"; id:"789012"}
producto30: { Categoria:"Dermatologico"; subcategoria: "Serum"; precio:"7.75"; id:"890123"}
producto31: { Categoria:"Higiene"; subcategoria: "Cuidado Dental"; precio:"5.99"; id:"432432"}
producto32: { Categoria:"Higiene"; subcategoria: "Cuidado Dental"; precio:"6.50"; id:"456789"}
producto33: { Categoria:"Higiene"; subcategoria: "Cuidado Dental"; precio:"7.75"; id:"567890"}
producto34: { Categoria:"Higiene"; subcategoria: "Cuidado Corporal"; precio:"8.99"; id:"678901"}
producto35: { Categoria:"Higiene"; subcategoria: "Cuidado Corporal"; precio:"5.50"; id:"789012"}
producto36: { Categoria:"Higiene"; subcategoria: "Cuidado Corporal"; precio:"7.75"; id:"890123"}
producto37: { Categoria:"Higiene"; subcategoria: "Cuidado del Cabello"; precio:"6.99"; id:"901234"}
producto38: { Categoria:"Higiene"; subcategoria: "Cuidado del Cabello"; precio:"8.50"; id:"123456"}
producto39: { Categoria:"Higiene"; subcategoria: "Cuidado del Cabello"; precio:"10.75"; id:"234567"}
producto40: { Categoria:"Higiene"; subcategoria: "Cuidado Intimo"; precio:"7.99"; id:"345678"}
producto41: { Categoria:"Higiene"; subcategoria: "Cuidado Intimo"; precio:"4.50"; id:"456789"}
producto42: { Categoria:"Higiene"; subcategoria: "Cuidado Intimo"; precio:"6.75"; id:"567890"}
producto43: { Categoria:"Higiene"; subcategoria: "Desodorantes"; precio:"8.99"; id:"678901"}
producto44: { Categoria:"Higiene"; subcategoria: "Desodorantes"; precio:"6.50"; id:"789012"}
producto45: { Categoria:"Higiene"; subcategoria: "Desodorantes"; precio:"7.75"; id:"890123"}
producto46: { Categoria:"Salud Mental"; subcategoria: "Antidepresivos"; precio:"12.99"; id:"432432"}
producto47: { Categoria:"Salud Mental"; subcategoria: "Antidepresivos"; precio:"10.50"; id:"456789"}
producto48: { Categoria:"Salud Mental"; subcategoria: "Antidepresivos"; precio:"11.75"; id:"567890"}
producto49: { Categoria:"Salud Mental"; subcategoria: "Ansioliticos"; precio:"9.99"; id:"678901"}
producto50: { Categoria:"Salud Mental"; subcategoria: "Ansioliticos"; precio:"7.50"; id:"789012"}
producto51: { Categoria:"Salud Mental"; subcategoria: "Ansioliticos"; precio:"8.75"; id:"890123"}
producto52: { Categoria:"Salud Mental"; subcategoria: "Estabilizadores del Animo"; precio:"11.99"; id:"901234"}
producto53: { Categoria:"Salud Mental"; subcategoria: "Estabilizadores del Animo"; precio:"9.50"; id:"123456"}
producto54: { Categoria:"Salud Mental"; subcategoria: "Estabilizadores del Animo"; precio:"10.75"; id:"234567"}
producto55: { Categoria:"Salud Mental"; subcategoria: "Tranquilizantes"; precio:"8.99"; id:"345678"}
producto56: { Categoria:"Salud Mental"; subcategoria: "Tranquilizantes"; precio:"6.50"; id:"456789"}
producto57: { Categoria:"Salud Mental"; subcategoria: "Tranquilizantes"; precio:"7.75"; id:"567890"}
producto58: { Categoria:"Salud Mental"; subcategoria: "Suplementos para el Cerebro"; precio:"13.99"; id:"678901"}
producto59: { Categoria:"Salud Mental"; subcategoria: "Suplementos para el Cerebro"; precio:"11.50"; id:"789012"}
producto60: { Categoria:"Salud Mental"; subcategoria: "Suplementos para el Cerebro"; precio:"12.75"; id:"890123"}
producto61: { Categoria:"Suplementos"; subcategoria: "Vitaminas"; precio:"9.99"; id:"432432"}
producto62: { Categoria:"Suplementos"; subcategoria: "Vitaminas"; precio:"8.50"; id:"456789"}
producto63: { Categoria:"Suplementos"; subcategoria: "Vitaminas"; precio:"10.75"; id:"567890"}
producto64: { Categoria:"Suplementos"; subcategoria: "Minerales"; precio:"7.99"; id:"678901"}
producto65: { Categoria:"Suplementos"; subcategoria: "Minerales"; precio:"6.50"; id:"789012"}
producto66: { Categoria:"Suplementos"; subcategoria: "Minerales"; precio:"8.75"; id:"890123"}
producto67: { Categoria:"Suplementos"; subcategoria: "Acidos Grasos Omega-3"; precio:"11.99"; id:"901234"}
producto68: { Categoria:"Suplementos"; subcategoria: "Acidos Grasos Omega-3"; precio:"10.50"; id:"123456"}
producto69: { Categoria:"Suplementos"; subcategoria: "Acidos Grasos Omega-3"; precio:"12.75"; id:"234567"}
producto70: { Categoria:"Suplementos"; subcategoria: "Proteinas"; precio:"8.99"; id:"345678"}
producto71: { Categoria:"Suplementos"; subcategoria: "Proteinas"; precio:"7.50"; id:"456789"}
producto72: { Categoria:"Suplementos"; subcategoria: "Proteinas"; precio:"9.75"; id:"567890"}
producto73: { Categoria:"Suplementos"; subcategoria: "Creatina"; precio:"12.99"; id:"678901"}
producto74: { Categoria:"Suplementos"; subcategoria: "Creatina"; precio:"11.50"; id:"789012"}
producto75: { Categoria:"Suplementos"; subcategoria: "Creatina"; precio:"13.75"; id:"890123"}
