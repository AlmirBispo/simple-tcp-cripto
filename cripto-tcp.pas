{
Yehovah is the holly name
Funções para criptografar e descriptografar dados pela TCP
Autor:Almir Bispo
Data:16/09/2024
Dependencia:nenhuma
}
{
	criptografar
	adata: dados string
	akey: chave privada
	step: 1 salto 
}
function encode_node(adata, akey: string; step: integer): string;
var
  i, part: integer;
  enc: string;
begin
  for i := 1 to length(adata) do
  begin
    part := int64(char(akey[i]));
    enc := enc + chr(int64(char(adata[i])) + (step shl 2 + (part shr 2)));
  end;
  Result := enc;
end;
{
	desccriptografar
	adata: dados string
	akey: chave privada
	step: 1 salto 
}
function decode_node(adata, akey: string; step: integer): string;
var
  i, part: integer;
  enc: string;
begin
  for i := 1 to length(adata) do
  begin
    part := int64(char(akey[i]));
    enc := enc + chr(int64(char(adata[i])) - (step shl 2 + (part shr 2)));
  end;
  Result := enc;
end;
////////////////// exemplo de como usar ///////////////////////////////
{

  msg := encode_node('ABACATE', 'YOURKEY', 1);
  ShowMessage(msg); //dados criptografados
  mout := decode_node(msg, 'YOURKEY', 1);
  ShowMessage(mout); dados descriptografados
}
