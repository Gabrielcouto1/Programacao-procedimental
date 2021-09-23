def maior():
    x=int(input("\nInsira um valor para x e y tal para estabelecer o intervalo (x,y).\nInsira o valor de x: "))
    y=int(input("Insira o valor de y: "))


    if x>y:
        print("\nO intervalo é determinado igual a: ")
        print(y , x)
        
        if y%2!=0:
            soma=y
        elif y%2==0:
            soma=y-1
        i=soma
        for i in range(x):
            if i%2!=0:
                soma=soma+i
                print(soma)
           
    elif y>x:
        
        print("\nO intervalo é determinado igual a: ")
        print(x , y)
        if x%2!=0:
            soma=x
        elif x%2==0:
            soma=x-1
        i=soma
        for i in range(y):
            if i%2!=0:
                soma=soma+i
                print(soma)
    elif x==y:
        soma=x

    print("\nO valor da soma dos números ímpares contidos no intervalo é igual a:")
    print(soma)
    
maior()
