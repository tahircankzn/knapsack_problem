canta = {}
liste1 = {} 
liste2 = {} 
canta_ağırlığı = 0

kapastelist = {}
kapaste = 0


def okuma(liste1,kapastelist):
    dosya = open("bag.txt","r")   
     
    kapastelist["kapaste"] = int(dosya.readline())
    
    for i in range(4):
        eşya = dosya.readline()
        eşya_ozellikleri = list(eşya.split(" "))
        birim_fiyat = int(eşya_ozellikleri[1]) / int(eşya_ozellikleri[0])
        liste1[birim_fiyat] = eşya_ozellikleri
    dosya.close()

okuma(liste1,kapastelist)
kapaste = kapastelist["kapaste"]

def hesap(canta_ağırlığı):
    metin = ""
    birim_fiyatlar = list(liste1.keys())

    birim_fiyatlar.sort(reverse=True) # büyükten küçüğe sıralanır

    for i in birim_fiyatlar:
        liste2[i] = liste1[i]
    ####
    for i in list(liste2.keys()):
        ağırlık,değer = liste2[i][0],liste2[i][1]
        if canta_ağırlığı + int(ağırlık) < int(kapaste):
            canta_ağırlığı+=int(ağırlık)
            metin = metin + ağırlık + "-" + değer + " "
            
        elif(canta_ağırlığı < int(kapaste)):
            
            a = int(kapaste) - canta_ağırlığı
            if a < int(ağırlık):
                b = (int(değer)/int(ağırlık))*a
                metin = metin + str(a) + "-" + str(b) + " "
            break
    return metin
   
def yazma():

    metin1 = list(hesap(canta_ağırlığı).split(" "))
    for i in range(4):
        print(metin1[i])
    

yazma()


