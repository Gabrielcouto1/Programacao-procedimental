def calc():
    sn=0
    div=0
    x=float(input("\nInsira um valor para o dividendo:  "))
    y=float(input("\nInsira um valor para o divisor:  "))

    if y==0:
        sn= input("\nNão é possível dividir por 0.\n\nDeseja inserir novos números?[S/N]")
        if sn == 'S' or sn == 's':
            calc()
        else :
            print("\nAté mais!\n")
    else:
        div=x/y
        print("\nO valor da divisão é igual a: ")
        print(div)
calc()
