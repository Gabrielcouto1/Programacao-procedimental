def med():
    n1=float(input("\nInsira um valor para a nota 1, com peso 2:  "))
    n2=float(input("\nInsira um valor para a nota 2, com peso 3:  "))
    n3=float(input("\nInsira um valor para a nota 3, com peso 5:  "))

    if n1>100 or n2>100 or n3>100 or n1<0 or n2<0 or n3<0:
        sn=input("Alguma nota inserida nao esta entre 0 e 100. Deseja comecar de novo?[S/N]")
        if sn == 's' or sn == 'S':
            med()
        else:
            return
            
    media=((n1*2)+(n2*3)+(n3*5))/10

    if media>=90 and media<=100:
        print("\nOtimo resultado! Sua nota foi: ")
        print(media)
    elif media>=70 and media<90:
        print("\nBom resultado! Sua nota foi: ")
        print(media)
    elif media>=50 and media<70:
        print("\nResultado regular. Sua nota foi: ")
        print(media)
    elif media>=0 and media<50:
        print("\nResultado ruim. Sua nota foi: ")
        print(media)
        
med()

