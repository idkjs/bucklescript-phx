open Phx_abstract;
type t = {
  .
  /*constructor(endPoint: string);*/
  /*defined as function*/
  /*normalizeEndpoint(endPoint: string): string;*/
  [@bs.meth] "normalizeEndpoint": string => string,
  /*endpointURL(): string;*/
  [@bs.get] "endpointURL": string,
  /*closeAndRetry(): void;*/
  [@bs.get] "closeAndRetry": void,
  /*ontimeout(): void;*/
  [@bs.get] "ontimeout": void,
  /*poll(): void;*/
  [@bs.get] "poll": void,
  /*send(body: any): void;*/
  /*defined as function*/
  /*close(code?: any, reason?: any): void;*/
  /*defined as function*/
};

/*constructor(endPoint: string);*/
[@bs.new] [@bs.module "phoenix"] external init: string => t = "LongPoll";

/*send(body: any): void;*/
[@bs.send] external send: (t, Js.t('body)) => void;
/*close(code?: any, reason?: any): void;*/
[@bs.send]
external close: (t, ~code: Js.t('code)=?, ~reason: Js.t('reason)=?) => void;
